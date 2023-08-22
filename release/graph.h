/*graph.h*/

//
// Graph class implemented as ...
//
//  map<string, set<string>>
// 
// For this implementation of graph, the vertices are 
// string, and the weights are doubles.  Example:
// 
//   graph  G;
//   G.addVertex("Chicago");
//   G.addVertex("New York");
//   G.addEdge("Chicago", "New York", -999.99);
//
// Randy Truong
// Professor Joe Hummel
// Northwestern University
// CS 211: Winter 2023
//
// This is my implementation of the graph, which takes
// in zero arguments and initializes an empty graph in the constructor,
// which will just be an adjacency list that is composed of a map, in
// which the list is represented through a map, in which
// the keys are strings and the values are sets of strings
// AKA the adjacent vertices. The adjacent vertices are then
// linked to the edgeTable, which is a map that contains
// pair<string, string> for the adjacent vertices as well
// a value that is the weight of the edge between them.
//  The aim for this implementation is
// O(log(v)) time for vertex-related funcitonality, while
// O(log(v)) for edge-related functionality.
//


#pragma once

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>


using namespace std;


class graph
{
private:


  map<string, set<string>> mainGraph; // map that has the key vertex as well as a set<string> of adjacent nodes.

  map<pair<string, string>, double> edgeTable; // easy lookup for <vertex, vertex> pairs

  set<string> vertexSet; // keeping easy track

  set<pair<string, string>> edgeSet; // avoiding duplicates!

  int numVertices; // represents the number of elements
                       // in the current graph
                       //
  int numEdges; // represents the current number of edges
                    // in the graph
                    //
  // Concept: Creating a map in which each "bucket" is a pair
  // of a vertex and its weight with the current vertex

public:
  //
  // default constructor: no parameters
  //
  graph();


  //
  // copy constructor: takes in a source graph g1
  graph(const graph& g1);
  //
  // NumVertices: no parameters
  // Note: this is just going to be an accessor
  // Returns the # of vertices currently in the graph.
  //
  int NumVertices() const;

  //
  // NumEdges: no parameters
  //
  // Returns the # of edges currently in the graph.
  //
  int NumEdges() const;

  //
  // addVertex: string v -> bool
  //
  // Adds the vertex v to the graph and returns true. However,
  // if v is already in the graph, it is not added again and 
  // false is returned. Additionally, if the
  //
  bool addVertex(string v);

  //
  // addEdge: string from, string to, double weight -> bool
  //
  // Adds the edge (from, to, weight) to the graph, and returns
  // true. If the vertices do not exist then no edge is added
  // and false is returned.
  //
  // NOTE: if the edge already exists, the existing edge weight
  // is overwritten with the new edge weight.
  //
  bool addEdge(string from, string to, double weight);

  //
  // getWeight: string from, string to, double weight -> bool
  //
  // Returns the weight associated with a given edge.  If 
  // the edge exists, the weight is returned via the reference
  // parameter and true is returned. If the edge does not 
  // exist, the weight parameter is unchanged and false is
  // returned.
  //
  bool getWeight(string from, string to, double& weight) const;

  //
  // neighbors: string v -> set<string>
  //
  // Returns a set containing the neighbors of v, i.e. all
  // vertices that can be reached from v along one edge. If
  // v does not exist, an empty set is returned.
  //
  set<string> neighbors(string v) const;

  //
  // getVertices: no params -> vector<string>
  //
  // Returns a vector containing all the vertices currently in
  // the graph. There is no guaranteed order to the vertices 
  // in the returned vector; the order should be considered 
  // random.
  //
  vector<string> getVertices() const;

  //
  // print: ostream& output -> void(prints)
  // 
  // Prints the internal state of the graph to the given 
  // output stream for debugging purposes. The output will
  // contain the # of vertices, the # of edges, the vertices,
  // and the edges. Vertices are output as strings and the 
  // weights as doubles.
  //
  // Example:
  //    graph G;
  //    ...
  //    G.print(cout);  // print to console
  //
  void print(ostream& output) const;

  //
  // member: string v -> bool
  //
  // Uses the STL function .find() to check if the
  // inputted vertex is a member of the mainGraph map
  bool member(string v) const;

  //
  // isEdge: string from, string to -> bool
  //
  // A helper function that checks whether or not
  // an edge exists. Reminder that this is a
  // DIRECTED graph, therefore, we only
  // need to check the bucket at the "from"
  // key.
  bool isEdge(string from, string to) const;

};
