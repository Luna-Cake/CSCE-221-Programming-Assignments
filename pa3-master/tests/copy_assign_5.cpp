#include "test_functions.h"
#include "RefBSTree.h"
#include <cstdlib>
#include <ctime>
#include <set>

std::set<int> set;
srand(time(NULL));

BSTree tree1;
BSTree tree2;
RefBSTree ttree1;

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree1.insert(num);
    ttree1.insert(num);
  }
}

tree1 = tree1;
tree2 = tree2;

ASSERT_TRUE(verify_equality(tree1, ttree1));
ASSERT_TRUE(verify_empty(tree2));