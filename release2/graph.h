/*graph.h*/

//
// Graph class implemented as ...
//
//  map<string, vector<pair<string, double>>>
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
  //
  // TODO: Create the graph in the form of an adjacency
  // list
  //
  // Checklist:
  // 1) Space requirement of at most O(V+E), where V is the
  // number of vertices and E is the number of of edges.
  // Note that this means "on the order of" so using
  // space 2V + E is still O(V+E), since we drop the constant.
  // 2) Adding a vertex may take at most O(log(V)) time.
  // 3) Adding an edge (x, y, w) may take at most O(E) time,
  // where E is the number of edges starting from x
  // 4) Getting an edge's weight may take at most O(log(V) + E)
  // time.
  // 5) Must support all possible weights (negative, 0, or
  // positive)
  // 6) Must support cyclic edges, i.e. an edge
  // from a vertex to itself
  // 7) Does not need to support multi-edges -- i.e. assume
  // that at most one edge from vertex x to vertex y.
  // - This means that a vertex can only have a single
  // any single edge; therefore x cannot be connected to y
  // multiple times and whatnot

  map<string, vector<pair<string ,double>>> mainGraph;

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
