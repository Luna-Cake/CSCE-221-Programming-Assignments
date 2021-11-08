#include "BSTree.h"
#include <climits>
#include <iostream>
#include <vector>



bool verify_empty(const BSTree& t) {
    bool b = t.get_root() == nullptr && t.get_size() == 0;
    if (!b) std::cout << "Error: Tree is not empty: " << std::endl;
    return  b;
}

void level_by_level_printer(Node *root)
{
    if(root == nullptr)
        return;

    bool hasNodes = true;
    std::vector<Node*> current_level;
    std::vector<Node*> next_level;
    current_level.push_back(root);
    while(hasNodes) {
        hasNodes = false;
        for(auto node : current_level) {
            if(node != nullptr) {
                std::cout << node->value << "["<<node->search_time<<"] ";
                if(node->left != nullptr)
                    hasNodes = true;
                if(node->right != nullptr)
                    hasNodes = true;

                next_level.push_back(node->left);
                next_level.push_back(node->right);
            } else {
                std::cout << "X ";
                next_level.push_back(nullptr);
                next_level.push_back(nullptr);
            }
        }
        std::cout << std::endl;
        current_level.clear();
        current_level = next_level;
        next_level.clear();
    }
}

// Returns true if tree1 and tree2 are deep copies of each other
bool verify_equality(const Node *tree1, const Node *tree2) {
    if (tree1 == nullptr || tree2 == nullptr) {
        return tree1 == tree2; // True if both pointers are null
    }

    // Check that they are equal, but the pointers are not the same
    return  (tree1 != tree2) && tree1->value == tree2->value &&
    tree1->search_time == tree2->search_time &&
    verify_equality(tree1->left, tree2->left) &&
    verify_equality(tree1->right, tree2->right);
}

template <typename T, typename U>
bool verify_equality(const T& tree1, const U& tree2) {
    if (tree1.get_size() != tree2.get_size()) {
        std::cout << "Error: Expected Size: " << tree2.get_size()
        << ", got instead: " << tree1.get_size() << std::endl;
        return false;
    }
    if (verify_equality(tree1.get_root(), tree2.get_root())) {
        return true;
    }
    std::cout << "Error: Expected Tree of the form: " << std::endl;
    level_by_level_printer(const_cast<Node*>(tree2.get_root()));
    std::cout << "Got instead: " << std::endl;
    level_by_level_printer(const_cast<Node*>(tree1.get_root()));
    return false;
}

int count_nodes(const Node *t) {
    if (t == nullptr) {
        return 0;
    }
    return 1 + count_nodes(t->left) + count_nodes(t->right);
}

bool verify_helper(const Node* tree1, int minimum=INT_MIN, int maximum=INT_MAX)
{
    if (tree1 == nullptr) {
        return true;
    }
    if (tree1->value < minimum || tree1->value > maximum) {
        return false;
    }
    return verify_helper(tree1->left, minimum, tree1->value) &&
         verify_helper(tree1->right, tree1->value, maximum);
}

// Returns true if the tree is valid. This means that it sorted and that
// the size is correct
bool verify_consistency(const BSTree& tree) {
    int size = tree.get_size();
    if (size != count_nodes(tree.get_root())) {
        return false;
    }
    return verify_helper(tree.get_root());
}

void recursive_mess(Node *ptr)
{
  if (ptr != nullptr) {
    ptr->search_time = rand();
    recursive_mess(ptr->left);
    recursive_mess(ptr->right);
  }
}
