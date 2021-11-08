#include "test_functions.h"
#include "RefBSTree.h"
#include <cstdlib>
#include <ctime>
#include <set>

BSTree tree1;
RefBSTree ttree1;

std::set<int> set;
srand(time(NULL));

for (int i = 0; i < 30; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree1.insert(num);
    ttree1.insert(num);
  }
}

BSTree tree2;
RefBSTree ttree2;

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree2.insert(num);
    ttree2.insert(num);
  }
}
ASSERT_EQ(verify_equality(tree2, ttree2),true);
ASSERT_EQ(verify_consistency(tree2),true);

BSTree t3;
RefBSTree tt3;
t3 = tree2 = move(tree1);
tt3 = ttree2 = move(ttree1);

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    tree2.insert(num);
    ttree2.insert(num);
  }
  num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    t3.insert(num);
    tt3.insert(num);
  }
}

ASSERT_EQ(verify_equality(tree1, ttree1),true);
ASSERT_EQ(verify_consistency(tree1),true);
ASSERT_EQ(verify_equality(tree2, ttree2),true);
ASSERT_EQ(verify_consistency(tree2),true);
ASSERT_EQ(verify_equality(t3, tt3),true);
ASSERT_EQ(verify_consistency(t3),true);