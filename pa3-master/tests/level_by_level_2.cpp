#include "RefBSTree.h"
#include "test_functions.h"
#include <sstream>
#include <set>

std::set<int> set;
BSTree t;
RefBSTree tt;

srand(time(NULL));

for (int i = 0; i < 10; i++) {
  int num = rand() % 10000;
  if (set.count(num) == 0) {
    set.insert(num);
    t.insert(num);
    tt.insert(num);
  }
}

stringstream ss, ss2;


t.print_level_by_level(ss);
tt.print_level_by_level(ss2);

bool b = true;
while (b && !ss.eof() && !ss2.eof()) {
  string str, str2;
  getline(ss, str);
  getline(ss2, str2);

  str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
  str2.erase(remove_if(str2.begin(), str2.end(), ::isspace), str2.end());
  b = str == str2;
}
b = b && ss.eof() && ss2.eof();

if (!b) {
  cout << "Error: Expected: " << endl;
  tt.print_level_by_level(cout);
  cout << "Got instead: " << endl;
  t.print_level_by_level(cout);
}

ASSERT_TRUE(b);

