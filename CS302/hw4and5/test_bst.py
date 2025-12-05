# Lian Zhu
# CS 302
# test_bst.py - Program #5

import pytest
from bst import Node, BST
from socialmedia import SocialMedia, LinkedIn, TikTok, Snapchat


def test_node_constructor():
    profile = SocialMedia("lian", 100)
    node = Node(profile)
    assert node.get_data() == profile
    assert node.get_left() is None
    assert node.get_right() is None


def test_node_set_get_left():
    node1 = Node(SocialMedia("lian", 100))
    node2 = Node(SocialMedia("alex", 50))
    node1.set_left(node2)
    assert node1.get_left() == node2


def test_node_set_get_right():
    node1 = Node(SocialMedia("lian", 100))
    node2 = Node(SocialMedia("sam", 150))
    node1.set_right(node2)
    assert node1.get_right() == node2


def test_node_set_get_data():
    profile1 = SocialMedia("lian", 100)
    profile2 = SocialMedia("lian", 200)
    node = Node(profile1)
    node.set_data(profile2)
    assert node.get_data() == profile2


def test_bst_constructor():
    bst = BST()
    assert bst.is_empty()
    assert bst.get_count() == 0


def test_bst_insert_single():
    bst = BST()
    profile = SocialMedia("lian", 100)
    bst.insert(profile)
    assert not bst.is_empty()
    assert bst.get_count() == 1


def test_bst_insert_multiple():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.insert(SocialMedia("alex", 50))
    bst.insert(SocialMedia("sam", 150))
    assert bst.get_count() == 3


def test_bst_insert_invalid_type():
    bst = BST()
    with pytest.raises(TypeError, match="Can only insert SocialMedia profiles"):
        bst.insert("not a profile")


def test_bst_insert_duplicate_updates():
    bst = BST()
    profile1 = SocialMedia("lian", 100)
    profile2 = SocialMedia("lian", 200)
    bst.insert(profile1)
    bst.insert(profile2)
    assert bst.get_count() == 1
    retrieved = bst.retrieve("lian")
    assert retrieved._followers == 200


def test_bst_retrieve_existing():
    bst = BST()
    profile = LinkedIn("lian", 100, 50, 10)
    bst.insert(profile)
    retrieved = bst.retrieve("lian")
    assert retrieved is not None
    assert retrieved._username == "lian"
    assert retrieved._followers == 100


def test_bst_retrieve_nonexistent():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    retrieved = bst.retrieve("nobody")
    assert retrieved is None


def test_bst_retrieve_from_empty():
    bst = BST()
    retrieved = bst.retrieve("lian")
    assert retrieved is None


def test_bst_retrieve_left_subtree():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.insert(SocialMedia("alex", 50))
    retrieved = bst.retrieve("alex")
    assert retrieved is not None
    assert retrieved._username == "alex"


def test_bst_retrieve_right_subtree():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.insert(SocialMedia("sam", 150))
    retrieved = bst.retrieve("sam")
    assert retrieved is not None
    assert retrieved._username == "sam"


def test_bst_remove_leaf():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.insert(SocialMedia("alex", 50))
    bst.insert(SocialMedia("sam", 150))
    bst.remove("alex")
    assert bst.get_count() == 2
    assert bst.retrieve("alex") is None


def test_bst_remove_one_child_left():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.insert(SocialMedia("alex", 50))
    bst.insert(SocialMedia("bob", 25))
    bst.remove("alex")
    assert bst.get_count() == 2
    assert bst.retrieve("bob") is not None


def test_bst_remove_one_child_right():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.insert(SocialMedia("sam", 150))
    bst.insert(SocialMedia("zoe", 200))
    bst.remove("sam")
    assert bst.get_count() == 2
    assert bst.retrieve("zoe") is not None


def test_bst_remove_two_children():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.insert(SocialMedia("alex", 50))
    bst.insert(SocialMedia("sam", 150))
    bst.insert(SocialMedia("bob", 25))
    bst.insert(SocialMedia("dan", 75))
    bst.remove("alex")
    assert bst.get_count() == 4
    assert bst.retrieve("alex") is None
    assert bst.retrieve("bob") is not None
    assert bst.retrieve("dan") is not None


def test_bst_remove_root():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    bst.remove("lian")
    assert bst.is_empty()
    assert bst.get_count() == 0


def test_bst_remove_nonexistent():
    bst = BST()
    bst.insert(SocialMedia("lian", 100))
    with pytest.raises(ValueError, match="not found"):
        bst.remove("nobody")


def test_bst_remove_from_empty():
    bst = BST()
    with pytest.raises(ValueError, match="empty tree"):
        bst.remove("lian")


def test_bst_display_all_empty(capsys):
    bst = BST()
    bst.display_all()
    captured = capsys.readouterr()
    assert "No profiles" in captured.out


def test_bst_display_all_with_profiles(capsys):
    bst = BST()
    bst.insert(LinkedIn("lian", 100, 50, 10))
    bst.insert(TikTok("alex", 200, 5, 1000))
    bst.insert(Snapchat("sam", 150, 50, 10))
    bst.display_all()
    captured = capsys.readouterr()
    assert "alex" in captured.out
    assert "lian" in captured.out
    assert "sam" in captured.out


def test_bst_alphabetical_order(capsys):
    bst = BST()
    bst.insert(SocialMedia("zoe", 100))
    bst.insert(SocialMedia("alex", 100))
    bst.insert(SocialMedia("sam", 100))
    bst.display_all()
    captured = capsys.readouterr()
    alex_pos = captured.out.find("alex")
    sam_pos = captured.out.find("sam")
    zoe_pos = captured.out.find("zoe")
    assert alex_pos < sam_pos < zoe_pos


def test_bst_display_by_platform(capsys):
    bst = BST()
    bst.insert(LinkedIn("lian", 100, 50, 10))
    bst.insert(TikTok("alex", 200, 5, 1000))
    bst.insert(LinkedIn("sam", 150, 30, 5))
    bst.display_by_platform("LinkedIn")
    captured = capsys.readouterr()
    assert "lian" in captured.out
    assert "sam" in captured.out
    assert "alex" not in captured.out


def test_bst_display_by_platform_none_found(capsys):
    bst = BST()
    bst.insert(LinkedIn("lian", 100, 50, 10))
    bst.display_by_platform("TikTok")
    captured = capsys.readouterr()
    assert "No TikTok profiles found" in captured.out


def test_bst_get_all_profiles():
    bst = BST()
    profile1 = LinkedIn("lian", 100, 50, 10)
    profile2 = TikTok("alex", 200, 5, 1000)
    profile3 = Snapchat("sam", 150, 50, 10)
    bst.insert(profile1)
    bst.insert(profile2)
    bst.insert(profile3)
    profiles = bst.get_all_profiles()
    assert len(profiles) == 3
    assert profile2 in profiles
    assert profile1 in profiles
    assert profile3 in profiles


def test_bst_mixed_platforms():
    bst = BST()
    bst.insert(LinkedIn("alice", 100, 50, 10))
    bst.insert(TikTok("bob", 200, 5, 1000))
    bst.insert(Snapchat("charlie", 150, 50, 10))
    bst.insert(LinkedIn("diana", 300, 100, 20))
    bst.insert(TikTok("eve", 250, 10, 5000))
    
    assert bst.get_count() == 5
    assert isinstance(bst.retrieve("alice"), LinkedIn)
    assert isinstance(bst.retrieve("bob"), TikTok)
    assert isinstance(bst.retrieve("charlie"), Snapchat)


def test_bst_complex_removal_sequence():
    bst = BST()
    names = ["lian", "alex", "sam", "bob", "dan", "zoe", "eve"]
    for name in names:
        bst.insert(SocialMedia(name, 100))
    
    assert bst.get_count() == 7
    
    bst.remove("bob")
    assert bst.get_count() == 6
    
    bst.remove("lian")
    assert bst.get_count() == 5
    
    bst.remove("zoe")
    assert bst.get_count() == 4
    
    remaining = bst.get_all_profiles()
    usernames = [p._username for p in remaining]
    assert "alex" in usernames
    assert "sam" in usernames
    assert "dan" in usernames
    assert "eve" in usernames