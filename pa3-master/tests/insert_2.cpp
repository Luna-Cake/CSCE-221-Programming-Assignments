#include "test_functions.h"
#include <cstdlib>
#include <ctime>
#include <set>

std::set<int> set;
BSTree tree1;

srand(time(NULL));

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    auto ptr = tree1.insert(num);
    ASSERT_EQ(ptr->value, num);
  }
}