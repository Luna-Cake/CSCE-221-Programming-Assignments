#include "graph.h"
#include "tagraph.h"
#include "testUtil.h"

Graph<string> student;
TAGraph<string> ta;

std::stringstream input = buildRandomGraphStr(16, 700);

student.buildGraph(input);
//return to beginning of file for next read
input.clear();
input.seekg(0);
ta.buildGraph(input);

ta.compute_indegree();
student.compute_indegree();

ta.topological_sort();
ASSERT_TRUE(student.topological_sort());
ASSERT_TRUE(checkTopologicalOrdering(ta, student));


stringstream studentStream;
student.print_top_sort(studentStream);

ASSERT_TRUE(checkPrintTopSort(ta, studentStream));