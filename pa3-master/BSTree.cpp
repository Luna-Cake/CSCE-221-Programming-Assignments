#include "BSTree.h"
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement 


// constructors
BSTree::BSTree() : size(0), root(nullptr) {}

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node)
{
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree)
{
    /*
      take input from the in stream, and build your tree
      input will look like
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while(in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
// If you try to use it without care, you will get a memory leak.
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}

// recursive function
int BSTree::get_total_search_time(Node* node)
{
  if (node != nullptr) {
    return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
  }
  return 0;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}


///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

// copy constructor
void helper_copy(BSTree& curr, Node& to_insert) {
  if (&to_insert == nullptr)
    return;
  curr.insert(to_insert.value);
  helper_copy(curr, *to_insert.left);
  helper_copy(curr, *to_insert.right);
}

BSTree::BSTree(const BSTree& other)
{
  root = nullptr;
  size = 0;
  helper_copy(*this, *other.root);
}

// move constructor
BSTree::BSTree(BSTree&& other)
{
  root = nullptr;
  size = 0;
  if (other.size != 0) {
    root = new Node(other.root->value);
    root->search_time = other.root->search_time;
    root->left = other.root->left;
    root->right = other.root->right;
    size = other.size;
  }
  other.root = nullptr;
  other.size = 0;
}

void helper_destruct(Node& node) {
  if (&node == nullptr)
    return;
  helper_destruct(*node.left);
  helper_destruct(*node.right);
  delete &node;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
    if (this != &other) {
      helper_destruct(*this->root);
      root = nullptr;
      helper_copy(*this, *other.root);
    }
    size = other.size;
    return *this;
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other)
{
    if (this != &other) {
      helper_destruct(*this->root);
      root = other.root;
      size = other.size;
      other.size = 0;
      other.root = nullptr;
    }

    return *this;
}

// destructor
BSTree::~BSTree()
{
    // Make sure to call delete on every node of the tree
    // You can use a recursive helper function to do this
    helper_destruct(*this->root);
    root = nullptr;
    size = 0;
}

Node* helper_insert(Node& curr, int obj, int search_cost) {
  if (obj >= curr.value) {
    if (curr.right == nullptr) {
      curr.right = new Node(obj);
      curr.right->search_time = search_cost;
      return curr.right;
    }
    else
      return helper_insert(*curr.right, obj, search_cost + 1);
  } else {
    if (curr.left == nullptr) {
      curr.left = new Node(obj);
      curr.left->search_time = search_cost;
      return curr.left;
    } else 
      return helper_insert(*curr.left, obj, search_cost + 1);
  }
  return nullptr;
}

Node* BSTree::insert(int obj) {
    /* insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node */
  size += 1;
  if (root == nullptr) {
    root = new Node(obj);
    root->search_time = 1;
    return root;
  }
  return helper_insert(*root, obj, 2);
}

Node* helper_search(Node& node, int obj) {
  if (&node == nullptr)
    return nullptr;
  else if (node.value > obj)
    return helper_search(*node.left, obj);
  else if (node.value < obj)
    return helper_search(*node.right, obj);
  else
    return &node;
}

Node* BSTree::search(int obj)
{
    /* recursively search down the tree to find the node that contains obj
    if you don't find anything return nullptr */
    return helper_search(*root, obj);
}

void helper_update(Node& root, int search_time) {
  if (&root == nullptr)
    return;
  root.search_time = search_time;
  helper_update(*root.left, search_time + 1);
  helper_update(*root.right, search_time + 1);
}
void BSTree::update_search_times()
{
    /* do a BFS or DFS of your tree and update the search times of all nodes at once
      The root has a search time of 1, and each child is 1 more than its parent */
    helper_update(*root, 1);
}

void helper_inorder(ostream& out, Node& node) {
  if (&node == nullptr)
    return;
  helper_inorder(out, *node.left);
  out << node << " ";
  helper_inorder(out, *node.right);
}

void BSTree::inorder(ostream& out)
{
    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
    helper_inorder(out, *root);
}


void BSTree::print_level_by_level(ostream& out)
{
    /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    Use X to mark empty positions. 
    
      if our tree looks like this:

       4
     2   6
    1   5 7
           9

    it should output:

    4[1]
    2[2] 6[2]
    1[3] X 5[3] 7[3]
    X X X X X X X 9[4]

    it might be helpful to do this part with the std::queue data structure.
    Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    for nodes like the left child of 6 above, and print the descendents of an empty
    node as also empty
    You can use the << operator to print nodes in the format shown */

    std::queue<Node*> print_order;
    print_order.push(this->root);
    int curr_level = 1;
    int num_nums = 1;
    int printed_nums = 0;

    if (this->root == nullptr)
      return;

    while (!print_order.empty()) {
      Node* temp = print_order.front();
      // std::cout << *temp << std::endl;
      if (num_nums > 0) {
        if (temp == nullptr) {
          out << "X ";
          print_order.push(nullptr);
          print_order.push(nullptr);
        }
        else {
          out << *temp << " ";
          if (temp->left != nullptr)
            num_nums += 1;
          if (temp->right != nullptr)
            num_nums += 1;
          
          print_order.push(temp->left);
          print_order.push(temp->right);
        }
        printed_nums += 1;
        if (printed_nums == pow(2, curr_level - 1)) {
          out << std::endl;
          curr_level += 1;
          printed_nums = 0;
        }
      } else 
          break;
      print_order.pop();
      if (temp != nullptr)
        num_nums -= 1;
    }
    if (printed_nums != 0) {
      for (int i = printed_nums; i < pow(2, curr_level - 1); i++)
        out << "X ";
      out << std::endl;
    }
}
