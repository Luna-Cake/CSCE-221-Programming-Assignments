#include "graph.h"
#include "tagraph.h"
#include "testUtil.h"

Graph<int> student;
TAGraph<int> ta;

string input_name = "input.data";
ifstream input(input_name);
if (!input) {
  cout << "Wrong or nonexisting input file. Email TA.\n";
  ASSERT_TRUE(false);
}

student.buildGraph(input);

bool raisedException = false;
try{
  //should throw any exception
  student.at(100);
}catch(...){
  raisedException = true;
}
ASSERT_TRUE(raisedException);

