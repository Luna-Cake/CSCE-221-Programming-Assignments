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

t.inorder(ss);
tt.inorder(ss2);

string str = ss.str();
string str2 = ss2.str();
if(str.size() == 0 && str2.size() != 0){
  cout << "!!!!!!!!!!!!!" << endl;
  cout << "Your output is empty. Did you print to cout insetead of the provided ostream?" << endl;
  cout << "!!!!!!!!!!!!!" << endl;
}

//cout << "Ignore:" << str << endl;
//cout << "Ignore: " << str2 << endl;

str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
str2.erase(remove_if(str2.begin(), str2.end(), ::isspace), str2.end());

bool b = str == str2;
if (!b) {
  cout << "Error: Expected: " << endl;
  tt.inorder(cout);
  cout << "Got instead: " << endl;
  t.inorder(cout);
}

ASSERT_TRUE(b);




