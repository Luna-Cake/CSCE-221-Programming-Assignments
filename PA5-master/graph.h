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
    return (v1.top_num < v2.top_num);
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

  bool detect_cycle(std::unordered_map<T, bool> visited, Vertex<T> node) {
    for (size_t i = 0; i < node.adj_list.size(); i++) {
      if (visited.find(node.adj_list[i])->second == true)
        return true;
      auto v = visited.find(node.adj_list[i]);
      v->second = true;
      return detect_cycle(visited, at(node.adj_list[i]));
    }
    return false;
  }

  void assign_top(std::unordered_map<T, bool>* visited, std::stack<T>* order, Vertex<T> node) {
    // std::cout << "CURR NODE: " << node.label << std::endl;

    auto visit_record = visited->find(node.label);

    if (visit_record->second)
      return;

    visit_record->second = true;

    for (size_t i = 0; i < node.adj_list.size(); i++) {
      auto curr_node = visited->find(node.adj_list[i]);
      if (!curr_node->second) {
        assign_top(visited, order, at(node.adj_list[i]));
      }
    }
    order->push(node.label);
    auto v = node_set.find(node.label);
    v->second.top_num = order->size();
    // std::cout << node.label << " " << v->second.top_num << std::endl;
  }

  // topological sort
  // return true if successful, false on failure (cycle)
  bool topological_sort(void){
    std::unordered_map<T, bool> visited;
    for (auto v : node_set)
      visited.insert({v.first, false});
    
    if (detect_cycle(visited, node_set.begin()->second))
      return false;
  
    for (auto v : visited)
      v.second = false;

    std::stack<T> order;
    for (auto v : node_set)
      assign_top(&visited, &order, v.second);
    

    return true;
  }; // Part 2

  // find indegree
  void compute_indegree(void){
    for (auto v : node_set) {
      for (size_t i = 0; i < v.second.adj_list.size(); i++) {
        Vertex<T> curr = at(v.second.adj_list[i]);
        auto node = node_set.find(v.second.adj_list[i]);
        node->second.set_indegree(curr.indegree + 1);
      }
    }
  } // Part 2

  // print topological sort into o
  //  if addNewline is true insert newline into stream
  void print_top_sort(ostream& o, bool addNewline=true)
  { 
    //TODO - implement things here
    std::priority_queue<Vertex<T>, std::vector<Vertex<T>>, VertexCompare<T>> print_order;

    for (auto v : node_set)
      print_order.push(v.second);

    while (!print_order.empty()) {
      o << print_order.top().label << " ";
      print_order.pop();
    }

    if(addNewline){o << '\n';};
  }; // Part 2
};

#endif
