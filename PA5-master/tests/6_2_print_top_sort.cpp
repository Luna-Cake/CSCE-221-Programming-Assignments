#include "graph.h"
#include "tagraph.h"
#include "testUtil.h"

Graph<string> student;
TAGraph<string> ta;

string input_name = "inputCourses.data";
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

ta.topological_sort();
student.topological_sort();

stringstream studentStream;
student.print_top_sort(studentStream);

ASSERT_TRUE(checkPrintTopSort(ta, studentStream));