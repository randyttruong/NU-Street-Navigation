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
// the keys are strings and the values are sets of strings
// AKA the adjacent vertices. The adjacent vertices are then
// linked to the edgeTable, which is a map that contains
// pair<string, string> for the adjacent vertices as well
// a value that is the weight of the edge between them.
//  The aim for this implementation is
// O(log(v)) time for vertex-related funcitonality, while
// O(log(v)) for edge-related functionality.
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

  auto iter2 = g1.edgeTable.begin();
  while ( iter2 != g1.edgeTable.end() )
  {
    this->edgeTable.emplace( iter2->first, iter2->second );
    iter2++;
  }
};

//
// NumVertices: no parameters
// Note: this is just going to be an accessor
// Returns the # of vertices currently in the graph.
//
int graph::NumVertices() const
{
  return (int) numVertices;
};

//
// NumEdges: no parameters
//
// Returns the # of edges currently in the graph.
////

int graph::NumEdges() const
{
  // Literally just going to get the size of the edgeSet
  // instance variable
  return (int) numEdges;

};

//
// addVertex: string v -> bool
//
// Adds the vertex v to the graph and returns true. However,
// if v is already in the graph, it is not added again and
// false is returned. Additionally, if the
//

bool graph::addVertex(string v)
{
  set<string>  edges;
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
// addEdge: string from, string to, double weight -> bool
//
// Adds the edge (from, to, weight) to the graph, and returns
// true. If the vertices do not exist then no edge is added
// and false is returned.
bool graph::addEdge(string from, string to, double weight)
{

  if ( !(member(from) && member(to)) )
    return false;


	if ( isEdge(from, to) )
	 {
     edgeTable[make_pair(from, to)] =  weight;
     return true;
	     // cout << "this is the current x: " << from << " and this is the current y:  " << to << "and this is their current magnitude: "<<  edge.second << endl;
	 }

   edgeTable[(make_pair(from, to))] =   weight;
   mainGraph[from].insert(to);
	 this->numEdges++;
	 return true;
};

//
// getWeight: string from, string to, double weight -> bool
//
// Returns the weight associated with a given edge.  If
// the edge exists, the weight is returned via the reference
// parameter and true is returned. If the edge does not
// exist, the weight parameter is unchanged and false is
// returned.
bool graph::getWeight(string from, string to, double& weight) const
{
  if ( this->member(from) && this->member(to) )
  {
    if (!isEdge(from, to))
      return false;

//    weight = mainGraph.at(from).at(to)->second;

    weight = edgeTable.at(make_pair(from, to));
    return true;

  }
  return false;
};


//
// neighbors: string v -> set<string>
//
// Returns a set containing the neighbors of v, i.e. all
// vertices that can be reached from v along one edge. If
// v does not exist, an empty set is returned.
set<string> graph::neighbors(string v) const
{

  set<string> neighbors;
  // Checking to see if the current vertex is even a member of the graph
  if ( !this->member(v) )
    return neighbors;

  // set<pair<string, double>> bucket = mainGraph.at(v);


  for ( string neighbor: mainGraph.at(v) )
  {
    neighbors.insert(neighbor);

  }


  return neighbors;
};


//
// getVertices: no params -> vector<string>
//
// Returns a vector containing all the vertices currently in
// the graph. There is no guaranteed order to the vertices
// in the returned vector; the order should be considered
// random.//

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
// print: ostream& output -> void(prints)
//
// Prints the internal state of the graph to the given
// output stream for debugging purposes. The output will
// contain the # of vertices, the # of edges, the vertices,
// and the edges. Vertices are output as strings and the
// weights as doubles.
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

    for ( string edge: iter->second )
    {
      cout << "(" << from << ", " << edge << ", " << edgeTable.at(make_pair(from, edge)) <<  ")" << endl; ;
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


  if (edgeTable.find(make_pair(from, to)) != edgeTable.end())
    return true;

  return false;
}
