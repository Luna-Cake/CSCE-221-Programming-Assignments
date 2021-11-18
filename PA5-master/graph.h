#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>

#include <iostream>

using namespace std;

//edits to this are likely not needed
template <class T>
struct Vertex {
  T label; // unique int for a vertex
  vector<T> adj_list;
  int indegree; // Part 2: number of nodes pointing in
  int top_num; // Part 2: topological sorting number
  Vertex(T l) : label(l) {indegree = 0, top_num = 0;} //Part 1
  // You may include default constructor optionally.

  void set_indegree(int new_degree) {
    indegree = new_degree;
  };
};

// optional, but probably helpful
template <class T>
ostream& operator<<(ostream &o, Vertex<T> v){
  o << v.label << ":";
  for (size_t i = 0; i < v.adj_list.size(); i++)
    o << " " << v.adj_list[i];
  return o;
};

// std::priority_queue may take takes three template parameters: <Type, ContainerType, Functor>
// syntax for custom compare functor follows
// Refer the instructions PDF last section for more information

template<class T>
class VertexCompare
{
public:
  bool operator()(Vertex<T> v1, Vertex<T> v2){
    //todo - implement here
    return false;
  }
};

template <class T>
class Graph {
private:
  //c++ stl hash table
  std::unordered_map<T, Vertex<T> > node_set;

  // alternatively:
  //c++ balanced binary tree (probably red-black but may be compiler dependent)
  // std::map<T, Vertex<T> > node_set;
  //  using this may negatively impact your runtime

  //Use other data fields if needed
public:
  Graph() {};  //No modification needed to default constructor. Can be used optionally if needed.
  ~Graph() {}; //No modification needed to destructor. Can be used optionally if needed.

  // build a graph - refer the instructions PDF for more information.
  void buildGraph(istream &input){
    std::string line;
    while (std::getline(input, line))
    {
      std::istringstream iss(line);
      
      T node_label;
      iss >> node_label;
      Vertex<T> new_vertex = Vertex(node_label);

      T adjacent;
      while (iss >> adjacent)
        new_vertex.adj_list.push_back(adjacent);

      node_set.insert({node_label, new_vertex});
    }
    compute_indegree();
  }

  // display the graph into o - refer the instructions PDF for more information.
  void displayGraph(ostream& o){
    for (auto v : node_set)
      o << v.second << std::endl;
  }

  //return the vertex at label, else throw any exception  - refer the instructions PDF for more information.
  Vertex<T> at(T label) {
    if (size() == 0)
      throw std::runtime_error("Empty graph.");

    auto node = node_set.find(label);
    if (node != node_set.end())
      return node->second;

    throw std::runtime_error("Label not in graph.");
  }

  //return the graph size (number of verticies)
  int size(void){
    return node_set.size();
  }

  // topological sort
  // return true if successful, false on failure (cycle)
  bool topological_sort(void){}; // Part 2

  // find indegree
  void compute_indegree(void){
    for (auto v : node_set) {
      for (size_t i = 0; i < v.second.adj_list.size(); i++) {
        Vertex<T> curr = at(v.second.adj_list[i]);
        auto node = node_set.find(v.second.adj_list[i]);
        node->second.set_indegree(curr.indegree + 1);
      }
    }

    for (auto v : node_set) {
      std::cout << "NODE: " << v.first << " DEGREE: " << v.second.indegree << std::endl;
    }
  } // Part 2

  // print topological sort into o
  //  if addNewline is true insert newline into stream
  void print_top_sort(ostream& o, bool addNewline=true)
  { 
    //TODO - implement things here
    
    if(addNewline){o << '\n';};
  }; // Part 2
};

#endif
