#include "graph.h"
#include "tagraph.h"
#include "testUtil.h"

Graph<int> student;
TAGraph<int> ta;

string input_name = "input2.data";
ifstream input(input_name);
if (!input) {
  cout << "Wrong or nonexisting input file. Email TA.\n";
  ASSERT_TRUE(false);
}

student.buildGraph(input);
//return to beginning of file for next read
input.clear();
input.seekg(0);
ta.buildGraph(input);

//TODO - rest of checking
ta.compute_indegree();
student.compute_indegree();
ASSERT_TRUE(compareIndegrees(ta, student));