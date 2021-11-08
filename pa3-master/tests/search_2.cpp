#include "RefBSTree.h"
#include "test_functions.h"
#include <set>

std::set<int> set;
BSTree tree1;

srand(time(NULL));

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree1.insert(num);
  }
}

for (auto num : set) {
  ASSERT_EQ(tree1.search(num)->value,num);
}