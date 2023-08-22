/* graph.cpp  */

//
// Randy Truong
// Professor Joe Hummel
// Northwestern University
// CS 211: Winter 2023
//

#include "graph.h"

using namespace std;


// graph()
//
// This is the constructor function for the grpah, which takes
// in zero arguments and initializes an empty graph, which
// will just be an adjacency list that is composed of a map, in
// which the list is represented through a map, in which
// the keys are strings and the values are vectors of
// string-double pairs. The aim for this implementation is
// O(log(v)) time for vertex-related funcitonality, while
// O(log(v) + ) for edge-related functionality.
//

//
// graph()
graph::graph()
{
  this->numEdges = 0;
  this->numVertices = 0;
};

//
// graph() copy constructor
graph::graph(const graph& g1)
{
  this->numEdges = g1.numEdges;
  this->numVertices = g1.numVertices;



  auto iter = g1.mainGraph.begin();
  while ( iter != g1.mainGraph.end() )
  {
    this->mainGraph.emplace( iter->first, iter->second );
    iter++;
  }
};
//
// NumVertices() (DONE)
int graph::NumVertices() const
{
  return (int) numVertices;
};

//
// NumEdges() (DONE)
int graph::NumEdges() const
{
  // Literally just going to get the size of the edgeSet
  // instance variable
  return (int) numEdges;

};

//
// AddVertex() (DONE)
bool graph::addVertex(string v)
{
  vector<pair<string, double>> edges;
  // Checking if there is a member or not
  if ( member(v) )
    return false;

  // If vertex is not a member, then just
  //
  mainGraph.emplace(v, edges);

  // cout << "I just added a vertex" << endl;
  this->numVertices = this->numVertices + 1;
  // cout << "this is the current number of vertices: " << this->NumVertices() << endl;

  return true;
};

//
// addEdge() (DONE)
bool graph::addEdge(string from, string to, double weight)
{
  // if ( isEdge(from, to) )
  if ( member(from) )
  {
      vector<pair<string, double>> bucket = mainGraph.at(from);

      for ( pair<string, double>& edge: mainGraph.at(from) )
      {
        if ( edge.first == to )
        {
          edge.second = weight;
          return true;
          // cout << "this is the current x: " << from << " and this is the current y:  " << to << "and this is their current magnitude: "<<  edge.second << endl;
        }

      }
      mainGraph[from].push_back(make_pair(to, weight));
      this->numEdges++;
      return true;
  }

  return false;
};

//
// getWeight() (DONE)
bool graph::getWeight(string from, string to, double& weight) const
{
  if ( this->member(from) && this->member(to) )
  {
    if (!isEdge(from, to))
      return false;

//    weight = mainGraph.at(from).at(to)->second;
    vector<pair<string, double>> bucket = mainGraph.at(from);

    for ( pair<string, double>& edge : bucket )
    {
      if ( edge.first == to )
        weight = edge.second;
    }
    return true;

  }
  return false;
};

//
// neighbors()
set<string> graph::neighbors(string v) const
{

  set<string> neighbors;
  // Checking to see if the current vertex is even a member of the graph
  if ( !this->member(v) )
    return neighbors;

  vector<pair<string, double>> bucket = mainGraph.at(v);

  for ( pair<string, double>& curr: bucket)
  {
    neighbors.insert(curr.first);
  }


  return neighbors;
};

//
// getVertices()
// This is a function that returns a set of vertices
vector<string> graph::getVertices() const
{

  vector<string> vertices;
  auto iter = mainGraph.begin();

  // Looping through the entire grtaph
  // Remember that mainGraph.end() refers to the element past-the-end
  while ( iter != mainGraph.end() )
  {
    vertices.push_back(iter->first);
    iter++;
  }

  return vertices;
};

//
// print()
//
void graph::print(ostream& output) const{
  // Requirements:
  //
  // # of vertices
  // # of edges
  // List of vertices (as a string)
  // Edges with vertices (in string form)
  //

  cout << "Number of Vertices: " << NumVertices() << endl;

  cout << "Number of Edges: " << NumEdges() << endl;

  cout << "Vertices: " ;
  for ( string vertex : getVertices() )
    cout << vertex << " ";

  cout << endl;

  cout << "Edges: " << endl;
  auto iter = mainGraph.begin();
  while ( iter != mainGraph.end() )
  {
    string from = iter->first;

    for ( pair<string, double> edge: iter->second )
    {
      cout << "(" << from << ", " << edge.first << ", " << edge.second <<  ")" << endl; ;
    } // for loop

    iter++;
  } // while loop
};

//
// member()
// Helper function that lets us know if a potential vertex
// already exists in the graph. Retursn true if vertex
// already exists. Returns false otherwise.
bool graph::member(string v) const
{
  if ( mainGraph.find(v) !=  mainGraph.end() )
    return true;

  return false;
};

//
// edge()
// Traverses a bucket the adjacency list. Returns true
// if the desired "to" edge is in the bucket, returns
// false otherwise.
bool graph::isEdge(string from, string to) const
{


  if ( mainGraph.find(from) != mainGraph.end() )
  {
    vector<pair<string,double>> bucket = mainGraph.at(from);
  	for ( pair<string, double>& edge: bucket)
  	{
  	  if ( edge.first == to )
  	    return true;
  	}
  }

  return false;
}
