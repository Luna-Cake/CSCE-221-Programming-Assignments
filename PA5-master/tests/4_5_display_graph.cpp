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

std::stringstream studentDisplay;
student.displayGraph(studentDisplay);

ta.compute_indegree();
student.compute_indegree();
ASSERT_TRUE(compareIndegrees(ta, student));