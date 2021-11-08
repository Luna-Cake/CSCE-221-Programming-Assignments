#include "test_functions.h"
BSTree tree1;

BSTree tree2(tree1);

ASSERT_TRUE(verify_empty(tree2));
