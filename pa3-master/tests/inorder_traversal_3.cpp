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
