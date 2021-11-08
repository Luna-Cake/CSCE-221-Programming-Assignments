#include "RefBSTree.h"
#include "test_functions.h"
#include <sstream>
#include <string>

stringstream ss, ss2;

BSTree t;
RefBSTree tt;

for (int i = 0; i < 4; i++) {
  t.insert(i);
  tt.insert(i);
}

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



