#include "graph.h"
#include "tagraph.h"
#include "testUtil.h"

Graph<int> student;
TAGraph<int> ta;

std::stringstream input = buildDisjointGraphInt(40, 700, 4);

student.buildGraph(input);
//return to beginning of file for next read
input.clear();
input.seekg(0);
ta.buildGraph(input);
ASSERT_TRUE(compareGraphs(ta,student));


ta.compute_indegree();
student.compute_indegree();

ta.topological_sort();
ASSERT_TRUE(student.topological_sort());
ASSERT_TRUE(checkTopologicalOrdering(ta, student));