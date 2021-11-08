#include "test_functions.h"
BSTree tree1;

BSTree tree2;
tree2 = std::move(tree1);

ASSERT_TRUE(verify_empty(tree1) && verify_empty(tree2));