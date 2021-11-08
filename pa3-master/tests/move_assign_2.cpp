#include "test_functions.h"
#include "RefBSTree.h"
BSTree tree1;
RefBSTree ttree1;
std::set<int> set;

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree1.insert(num);
    ttree1.insert(num);
  }
}

BSTree tree2;
for (int i = 0; i < 20; i++) {
    tree2.insert(i*i);
}
auto ptr = tree1.get_root()->left;
tree2 = std::move(tree1);

ASSERT_TRUE(tree2.get_root()->left == ptr);
ASSERT_TRUE(verify_empty(tree1));
ASSERT_TRUE(verify_equality(tree2, ttree1));
