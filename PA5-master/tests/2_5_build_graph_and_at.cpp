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

ASSERT_TRUE(compareGraphs(ta,student));