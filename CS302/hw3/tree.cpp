// Lian Zhu
// CS302
// tree.cpp


#include "tree.h"

using namespace std;

// Node constructor
Node::Node() : num_children(0), num_keys(0)
{
  keys.clear();
  children.fill(nullptr);
}

// Node argument constructor
Node::Node(Racer* & src) : num_children(0), num_keys(0)
{
  keys.clear();
  if (src) 
  {
    keys.push_back(src);
    num_keys = 1;
  }
  children.fill(nullptr);
}

// Node destructor
Node::~Node()
{
  keys.clear();
  children.fill(nullptr);
  num_children = 0;
  num_keys = 0;
}

int Node::insert_key(Racer* & key)
{
  if (!key) return 0;
  if (num_keys >= 3) return 0; // full
  int pos = 0;
  while (pos < num_keys && *(keys[pos]) < *key)
  {
    ++pos;
  }
  
  keys.insert(keys.begin() + pos, key);
  ++num_keys;
  return 1;
}

int Node::find_key(Racer* & key) const
{
  if (!key) return -1;
  for (int i = 0; i < num_keys; ++i)
  {
    if (*(keys[i]) == *key) return i;
  }
  return -1;
}

// Tree constructor
Tree::Tree() : root(nullptr)
{
}

// Tree destructor
Tree::~Tree() 
{
  if (root) 
  {
    delete_tree(root);
  }
}

// delete the tree
void Tree::delete_tree(Node* & curr)
{
  if (!curr) return;
  for (auto & child : curr->children) 
  {
    if (child) 
    {
      delete_tree(child);
      child = nullptr;
    }
  }
  for (auto key : curr->keys)
  {
    if (key) 
    {
      delete key;
      key = nullptr;
    }
  }
  delete curr;
  curr = nullptr;
}

// wrapper display
int Tree::display() const
{
  if (!root) return 0;
  return display(root);
}

// recursive display
int Tree::display(Node* curr) const
{
  if (!curr) return 0;
  int count = 0;
  for (int i = 0; i < curr->num_keys; ++i)
  {
    // display ith child
    count += display(curr->children[i]);

    // display key i 
    if (curr->keys[i])
    {
      curr->keys[i]->display();
      ++count;
    }

  }
  // last child
  count += display(curr->children[curr->num_keys]);
  return count;
}

// wrapper insert
bool Tree::insert(Racer* & data)
{
  if (!data) return false;
  // empty tree
  if (!root)
  {
    root = new Node(data);
    return true;
  }

  // root is full, then split
  if (root->num_keys >= 3)
  {
    Node* old_root = root;
    Node* new_root = new Node();
    root = new_root;
    root->children[0] = old_root;
    root->num_children = 1;

    split_child(root, 0, old_root);
  }

  // its not full 
  return insert_non_full(root, data);
}

// split child helper function
void Tree::split_child(Node*& parent, int index, Node*& child)
{
  // new node to hold upper half of child keys
  Node* new_node = new Node();
  new_node->num_keys = 1;

  // move thje middle key up to the parent
  parent->keys.insert(parent->keys.begin() + index, child->keys[1]);
  parent->num_keys++;

  // move third key to new node
  new_node->keys.push_back(child->keys[2]);

  // keep first key in original child
  child->keys.resize(1);
  child->num_keys = 1;

  // if it is not a leaf, move the children too 
  if (child->num_children > 0)
  {
    new_node->children[0] = child->children[2];
    new_node->children[1] = child->children[3];
    new_node->num_children = 2;

    child->children[2] = nullptr;
    child->children[3] = nullptr;
    child->num_children = 2;
  }

  // insert this new node as parents child
  for (int i = parent->num_children; i > index + 1; --i)
  {
    parent->children[i] = parent->children[i-1];
  }

  parent->children[index + 1] = new_node;
  ++parent->num_children;
}

// helper function to insert into a node that is guaranteed not full
bool Tree::insert_non_full(Node* & curr, Racer* & data)
{
  int i = curr->num_keys-1;

  // leaf node
  if (curr->num_children == 0)
  {
    for (auto & key: curr->keys)
    {
      // check duplicate
      if (*key == *data) return false;
    }

    // make room for new key
    curr->keys.push_back(nullptr);

    while (i >= 0 && *(data) < *(curr->keys[i])) 
    {
      curr->keys[i+1] = curr->keys[i];
      --i;
    }

    curr->keys[i+1] = data;
    curr->num_keys += 1;
    return true;
  }
  // not a leaf node
  else 
  {
    while (i >= 0 && *(data) < *(curr->keys[i])) 
    {
      --i;
    }
    ++i; // this is the index for the child to descend to
    
    // if child is full
    if (curr->children[i]->num_keys>=3) 
    {
      split_child(curr, i, curr->children[i]);

      // after splitting, decide which child to descend
      if (*(curr->keys[i]) < *(data)) ++i;
    }

    return insert_non_full(curr->children[i], data);
  }
}

// race all wrapper
int Tree::race_all() const
{
  if (!root) return 0;
  return race_all(root);
}

// recursive race all
int Tree::race_all(Node* curr) const
{
  if (!curr) return 0;
  int count = 0;
  for (int i = 0; i < curr->num_keys; ++i)
  {
    // race all racers in the ith child
    count += race_all(curr->children[i]);
    
    // race the ith key racer
    if (curr->keys[i])
    {
      curr->keys[i]->race();
      ++count;
    }
  }

  // race all racers in last child
  count += race_all(curr->children[curr->num_keys]);
  return count;
}

// wrapper celebrate
int Tree::celebrate_all() const
{
  if (!root) return 0;
  return celebrate_all(root);
}

// recursive race all
int Tree::celebrate_all(Node* curr) const
{
  if (!curr) return 0;
  int count = 0;
  for (int i = 0; i < curr->num_keys; ++i)
  {
    // race all racers in the ith child
    count += celebrate_all(curr->children[i]);
    
    // race the ith key racer
    if (curr->keys[i])
    {
      curr->keys[i]->celebrate();
      ++count;
    }
  }

  // race all racers in last child
  count += celebrate_all(curr->children[curr->num_keys]);
  return count;
}
