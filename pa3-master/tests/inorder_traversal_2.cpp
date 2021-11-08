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
t.inorder(ss);
tt.inorder(ss2);

string str = ss.str();
str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
string str2 = ss2.str();
str2.erase(remove_if(str2.begin(), str2.end(), ::isspace), str2.end());

bool b = str == str2;
if (!b) {
  cout << "Error: Expected: " << endl;
  tt.inorder(cout);
  cout << "Got instead: " << endl;
  t.inorder(cout);
}

ASSERT_TRUE(b);

