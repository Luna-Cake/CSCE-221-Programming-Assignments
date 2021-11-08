#include "test_functions.h"
#include "RefBSTree.h"
#include <cstdlib>
#include <ctime>
#include <set>

std::set<int> set;
BSTree tree1;
RefBSTree ttree1;

srand(time(NULL));

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree1.insert(num);
    ttree1.insert(num);
  }
}

BSTree tree2(tree1);

ASSERT_TRUE(verify_equality(tree2, ttree1));
ASSERT_NE(tree2.get_root(), tree1.get_root());