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

ASSERT_TRUE(verify_equality(tree1, ttree1));