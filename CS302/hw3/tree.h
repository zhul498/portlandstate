// Lian Zhu
// CS302
// tree.h

#pragma once
#include "racer.h"
#include <vector> // data structure for each node
#include <array>



// Node class for a 2-3-4 tree
class Node
{
  public:
    Node(); // Default constructopr
    Node(Racer* & src); // argument constructor for when we rebalance the tree
    ~Node(); // destructor
  
    int insert_key(Racer* & key); // insert a key within a node
    int find_key(Racer* & key) const; // find a key within a node


    // nothing is private to avoid getters
    std::vector<Racer*> keys; // Node data
    std::array<Node*, 4> children; // 2-3-4 tree
    int num_children;
    int num_keys;

};


// Tree class
class Tree
{
  public:
    Tree(); // constructor
    ~Tree(); // destructor
             //
    bool insert(Racer* & data); // insert a node
    int display() const; // display the tree
    int race_all() const;
    int celebrate_all() const;


  private:
    Node* root;
    void split_child(Node*& parent, int index, Node*& child); // split the child when needed
    bool insert_non_full(Node*& curr, Racer* & data); 
    bool insert(Racer* & data, Node* & parent, Node* & curr); 
    void delete_tree(Node* & curr); // delete the tree
    int display(Node* curr) const; // display the tree
    int race_all(Node* curr) const;
    int celebrate_all(Node* curr) const;
};



