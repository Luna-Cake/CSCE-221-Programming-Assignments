#include "graph.h"
#include "tagraph.h"
#include "testUtil.h"

Graph<int> student;
TAGraph<int> ta;

std::stringstream input = buildCyclicalGraphInt(16, 700);

student.buildGraph(input);
//return to beginning of file for next read
input.clear();
input.seekg(0);
ta.buildGraph(input);

//Need to check this so that we know they actually buld the graph
ASSERT_TRUE(compareGraphs(ta, student));

ta.compute_indegree();
student.compute_indegree();
ASSERT_TRUE(compareIndegrees(ta, student));

ta.topological_sort();
ASSERT_FALSE(student.topological_sort());
//ASSERT_TRUE(checkTopologicalOrdering(ta, student));