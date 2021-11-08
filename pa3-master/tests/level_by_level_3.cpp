#include "RefBSTree.h"
#include "test_functions.h"
#include <sstream>

stringstream ss, ss2;

BSTree t;
RefBSTree tt;
t.insert(4);
t.insert(6);
t.insert(7);
t.insert(5);
t.insert(2);
t.insert(3);
t.insert(1);

tt.insert(4);
tt.insert(6);
tt.insert(7);
tt.insert(5);
tt.insert(2);
tt.insert(3);
tt.insert(1);

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


