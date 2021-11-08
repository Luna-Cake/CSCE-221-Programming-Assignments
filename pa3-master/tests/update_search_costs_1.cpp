#include "RefBSTree.h"
#include "test_functions.h"

BSTree t;
RefBSTree tt;

std::set<int> set;
srand(time(NULL));

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    t.insert(num);
    tt.insert(num);
  }
}
recursive_mess(const_cast<Node*>(t.get_root()));
t.update_search_times();
tt.update_search_times();

ASSERT_EQ(t.get_average_search_time(),tt.get_average_search_time());