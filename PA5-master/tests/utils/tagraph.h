

#ifndef TAGRAPH_H
#define TAGRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;


template <class T>
struct TAVertex {
  T label; // unique int for a vertex
  vector<T> adj_list;
  int indegree; // Part 2: number of nodes pointing in
  int top_num; // Part 2: topological sorting number
  TAVertex(T l) : label(l) {top_num = 0; label = l;} //Part 1
};

template <class T>
ostream& operator<<(ostream &o, TAVertex<T> v){
    // Removed: Leaking Implementation Details
}


// syntax for custom compare functor
template<class T>
class TAVertexCompare
{
public:
  bool operator()(TAVertex<T> v1, TAVertex<T> v2){
    //recall, the operation is less than and
    //  used in a maximizing priority queue
    //so the comparison must be reversed
    // Removed: Leaking Implementation Details
  }
};

template <class T>
class TAGraph {
public:
  //c++ stl hash table
  unordered_map<T, TAVertex<T>> node_set;
  //Add other data fields if needed
public:
  TAGraph() {};  // default constructor
  ~TAGraph() {};
  // build a graph
  void buildGraph(istream &input){
    // Removed: Leaking Implementation Details
  }
  // display the graph
  void displayGraph(ostream& o){
    // Removed: Leaking Implementation Details
  };

  //return the vertex at label, else throw exception
  TAVertex<T> at(T label){
    // Removed: Leaking Implementation Details
  }

  //return the graph size
  int size(){
    // Removed: Leaking Implementation Details
  }
  // topological sort
  // return true if successful, false on failure (cycle)
  bool topological_sort(){
    // Removed: Leaking Implementation Details
  }; // Part 2
  // find indegree
  void compute_indegree(){
    // Removed: Leaking Implementation Details
  }; // Part 2
  // print topological sort
  void print_top_sort(ostream& o, bool addNewline=true)
  { 
    // Removed: Leaking Implementation Details
  }; // Part 2
};

#endif
