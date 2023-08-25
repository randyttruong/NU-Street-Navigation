/* main.cpp */

// Randy Truong
// Northwestern University
// Professor Joe Hummel
// 11 March 2023
//
// Header:
// This is a program that emulates the 'graph' class that was
// introduced in the previous project07. The implementation
// of the graph consists of a map, where the keys are strings,
// and the values are vectors of string-double pairs. The
// ADT I used was the adjacency list, since it allows for
// logarithmic vertex checking and adding, as well as
// edge adding, while edge lookup does require
// O(log(V)) for bucket lookup +  O(log(V) + e) for edge lookup,
// making it O(log(V) +  which meets
// the project reqs. This file seeks to test the functionality
// of this graph.
//


#include <iostream>
#include <vector>
#include <map>
#include "gtest/gtest.h"
#include "graph.h"

using namespace std;

//
// test01
TEST(testing, test01)
{
	ASSERT_TRUE( 2 != 3 );
}

//
// test02
//
TEST(testing, test02)
{
	ASSERT_TRUE( 2 == 2 );
}

//
// Guidelines
//

//
// test03
// This is a non-trivial test that i) checks if the NumVertices() function
// is updating hte graph's numVertices variable and ii)
// also prevents the user from adding duplicate vertices into
// the graph.
TEST(testing, test03)
{
    graph g;

    // adding vertices
    bool test1 = g.addVertex("mushrooms");
    cout << g.NumVertices() << endl;
    ASSERT_TRUE(g.NumVertices() == 1);
    bool test2 = g.addVertex("olives");
    ASSERT_TRUE(g.NumVertices() == 2);
    bool test3 = g.addVertex("orange");
    ASSERT_TRUE(g.NumVertices() == 3);
    bool test4 = g.addVertex("burrito");
    ASSERT_TRUE(g.NumVertices() == 4);
    bool test5 = g.addVertex("pepperoni");
    ASSERT_TRUE(g.NumVertices() == 5);
    bool test6 = g.addVertex("jalapenos");
    ASSERT_TRUE(g.NumVertices() == 6);
    bool test7 = g.addVertex("corn");
    ASSERT_TRUE(g.NumVertices() == 7) ;
    bool test8 = g.addVertex("green onion");
    ASSERT_TRUE(g.NumVertices() == 8 );

    // adding edges

    // assertions
    ASSERT_TRUE( g.addVertex("mushrooms") == false );
    ASSERT_TRUE ( g.addVertex("olives") == false );
    ASSERT_TRUE( g.addVertex("orange" ) == false );
    ASSERT_TRUE( g.addVertex("burrito" ) == false );
    ASSERT_TRUE( g.addVertex("pepperoni") == false );
    ASSERT_TRUE( g.addVertex("jalapenos") == false );
    ASSERT_TRUE( g.addVertex("corn") == false );
    ASSERT_TRUE( g.addVertex("corn") == false );
    ASSERT_TRUE( g.addVertex("green onion") == false);
    ASSERT_TRUE( g.addVertex( "test" ));

    g.print(cout);

}

//
// test04
// This is a non-trivial test that makes sure i) if the
// NumVertices() function is properly updating the numVertices
// variable and ii) if the getWeight() function is not only
// properly returning the right boolean, but is also updating
// the actual magnitude of the edge in the graph. Finally,
// we also check to see that the function actually
// returns false whenever the user tries to grab an edge
// that doesn't exist.
//
TEST(testing, test04)
{
    graph g;

    // adding vertices
    bool test1=g.addVertex("insert text");
    ASSERT_TRUE( g.NumVertices() == 1 );
    bool test2=g.addVertex("jesus");
    ASSERT_TRUE( g.NumVertices() == 2 );
    bool test3=g.addVertex("mcdonalds");
    ASSERT_TRUE( g.NumVertices() == 3 );
    bool test4=g.addVertex("coffee");
    ASSERT_TRUE( g.NumVertices() == 4 );
    bool test5=g.addVertex("wingstop");
    ASSERT_TRUE( g.NumVertices() == 5 );
    bool test6=g.addVertex("ipad");
    ASSERT_TRUE( g.NumVertices() == 6 );
    bool test7=g.addVertex("golang");
    ASSERT_TRUE( g.NumVertices() == 7 );
    bool test8=g.addVertex("codeine");
    ASSERT_TRUE( g.NumVertices() == 8 );

    bool weight;
    double magnitude;
    g.addEdge("insert text", "jesus", 1);
    weight = g.getWeight( "insert text", "jesus", magnitude);
    ASSERT_TRUE( weight );
    ASSERT_TRUE( magnitude == 1 );
    g.addEdge("mcdonalds", "ipad", 2);
    weight = g.getWeight("mcdonalds", "ipad", magnitude);
    ASSERT_TRUE( weight );
    ASSERT_TRUE( magnitude == 2 );
    g.addEdge("wingstop", "golang", 3);
    weight = g.getWeight("wingstop", "golang", magnitude);
    ASSERT_TRUE( weight );
    ASSERT_TRUE( magnitude == 3 );
    g.addEdge("coffee", "codeine", 4);
    weight = g.getWeight("coffee", "codeine", magnitude);
    ASSERT_TRUE( weight );
    ASSERT_TRUE( magnitude == 4 );

    weight = g.getWeight("something1", "something2", magnitude);
    ASSERT_TRUE( weight == false );
    ASSERT_TRUE( magnitude == 4);

    // fake edges
    //

    weight = g.getWeight("big 10", "wingstop", magnitude );
    ASSERT_TRUE ( weight == false );
    ASSERT_TRUE ( magnitude == 4 ); // the last one entered
                                    //
                                    //
    g.print(cout);



    // adding edges
}

//
// test05
TEST(testing, test05)
{
    graph g;

    // adding vertices
    bool test1=g.addVertex("basket");
    bool test2=g.addVertex("shoe");
    bool test3=g.addVertex("water");
    bool test4=g.addVertex("table");
    bool test5=g.addVertex("electricdity");
    bool test6=g.addVertex("magnet");
    bool test7=g.addVertex("phone");
    bool test8=g.addVertex("toilet");

    g.print(cout);
    // adding edges
}

//
// test06
// This is a non trivial test  that checks the functionality
// of addVertex(), addEdge(), getWeight(), and NumEdges() by
// procedurally adding vertices and edges and checking on
// the size of the graph.
TEST(testing, stressTest)
{
    graph g;

    bool added;
    bool weight;
    double magnitude;
    // adding vertices
    ASSERT_TRUE( g.NumVertices() == 0 );
    added=g.addVertex("A");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 1 );
    added=g.addVertex("B");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 2);
    added=g.addVertex("C");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 3 );
    added=g.addVertex("D");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 4 );
    added=g.addVertex("E");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 5);
    added=g.addVertex("F");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 6 );
    added=g.addVertex("G");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 7 );
    added=g.addVertex("H");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 8 );

    // adding edges (remember that you need at least 12)
    weight = g.addEdge("A", "A", 5);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("A", "A", magnitude) );
    ASSERT_TRUE( magnitude == 5 );
    ASSERT_TRUE( g.NumEdges() == 1);

    weight = g.addEdge("A", "B", 5);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("A", "B", magnitude) );
    ASSERT_TRUE( magnitude == 5 );
    ASSERT_TRUE( g.NumEdges() == 2);

    weight = g.addEdge("A", "C", 5);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("A", "C", magnitude) );
    ASSERT_TRUE( magnitude == 5 );
    ASSERT_TRUE( g.NumEdges() == 3);

    weight = g.addEdge("B", "B", 7);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("B", "B", magnitude) );
    ASSERT_TRUE( magnitude == 7 );
    ASSERT_TRUE( g.NumEdges() == 4);

    weight = g.addEdge("B", "C", 7);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("B", "C", magnitude) );
    ASSERT_TRUE( magnitude == 7 );
    ASSERT_TRUE( g.NumEdges() == 5);

    weight = g.addEdge("B", "D", 7);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("B", "D", magnitude) );
    ASSERT_TRUE( magnitude == 7 );
    ASSERT_TRUE( g.NumEdges() == 6);

    weight = g.addEdge("C", "C", 8);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("C", "C", magnitude) );
    ASSERT_TRUE( magnitude == 8 );
    ASSERT_TRUE( g.NumEdges() == 7);

    weight = g.addEdge("C", "D", 8);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("C", "D", magnitude) );
    ASSERT_TRUE( magnitude == 8 );
    ASSERT_TRUE( g.NumEdges() == 8);

    weight = g.addEdge("C", "E", 8);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("C", "E", magnitude) );
    ASSERT_TRUE( magnitude == 8 );
    ASSERT_TRUE( g.NumEdges() == 9);

    weight = g.addEdge("D", "D", 9);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("D", "D", magnitude) );
    ASSERT_TRUE( magnitude == 9 );
    ASSERT_TRUE( g.NumEdges() == 10);

    weight = g.addEdge("D", "E", 9);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("D", "E", magnitude) );
    ASSERT_TRUE( magnitude == 9 );
    ASSERT_TRUE( g.NumEdges() == 11);

    weight = g.addEdge("D", "F", 9);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("D", "F", magnitude) );
    ASSERT_TRUE( magnitude == 9 );
    ASSERT_TRUE( g.NumEdges() == 12);

    weight = g.addEdge("E", "E", 10);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("E", "E", magnitude) );
    ASSERT_TRUE( magnitude == 10 );
    ASSERT_TRUE( g.NumEdges() == 13);

    weight = g.addEdge("E", "F", 10);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("E", "F", magnitude) );
    ASSERT_TRUE( magnitude == 10 );
    ASSERT_TRUE( g.NumEdges() == 14);

    weight = g.addEdge("E", "G", 10);
    ASSERT_TRUE(weight);
    ASSERT_TRUE( g.getWeight("E", "G", magnitude) );
    ASSERT_TRUE( magnitude == 10 );
    ASSERT_TRUE( g.NumEdges() == 15);

    g.print(cout);

}


//
// test07
// This is a non-trivial test that makes sure that addEdge()
// updates an existing edge whenever an existing edge is
// inputted into the function. I check the magnitude of the
// edges, seeing that they are updated whenever the actual
// edge is updated, as well. I also check to see that the
// edge number/count does not change in the event that an
// edge is updated, rather than added. I also use
// this test to ensure that the graph does support
// edges in which the vertex is both the start and end point.
TEST(testing, test07)
{
    graph g;

    bool added;
    bool weight;
    double magnitude;

    // adding vertices
    ASSERT_TRUE( g.NumVertices() == 0 );
    added=g.addVertex("a");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 1 );
    added=g.addVertex("b");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 2 );
    added=g.addVertex("c");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 3 );
    added=g.addVertex("d");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 4 );
    added=g.addVertex("e");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 5 );
    added=g.addVertex("f");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 6 );
    added=g.addVertex("g");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 7 );
    added=g.addVertex("h");
    ASSERT_TRUE(added);
    ASSERT_TRUE( g.NumVertices() == 8 );

    // adding edges
    ASSERT_TRUE( g.NumEdges() == 0 );
    added = g.addEdge("a", "b", 1);
    ASSERT_TRUE( g.NumEdges() == 1 );
    weight = g.getWeight("a", "b", magnitude);

    added = g.addEdge("a", "b", 2);
    ASSERT_TRUE( g.NumEdges() == 1 );
    weight = g.getWeight("a", "b", magnitude);
    cout << "this is the current magnitude: " << magnitude << endl;
    ASSERT_TRUE ( magnitude == 2 );

    added = g.addEdge("a", "c", 1);
    ASSERT_TRUE( g.NumEdges() == 2 );
    weight = g.getWeight("a", "c", magnitude);
    ASSERT_TRUE(magnitude == 1 );

    added = g.addEdge("a", "d", 1);
    ASSERT_TRUE( g.NumEdges() == 3 );
    weight = g.getWeight("a", "d", magnitude);
    ASSERT_TRUE (magnitude == 1);

    added = g.addEdge("b", "b", 1);
    ASSERT_TRUE( g.NumEdges() == 4 );
    weight = g.getWeight("b", "b", magnitude);
    ASSERT_TRUE(magnitude == 1 );

    added = g.addEdge("b", "b", 1);
    ASSERT_TRUE( g.NumEdges() == 4 );
    weight = g.getWeight("b", "b", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("b", "c", 1);
    ASSERT_TRUE( g.NumEdges() == 5 );
    weight = g.getWeight("b", "c", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("b", "d", 1);
    ASSERT_TRUE( g.NumEdges() == 6 );
    weight = g.getWeight("b", "d", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("c", "c", 1);
    ASSERT_TRUE( g.NumEdges() == 7 );
    weight = g.getWeight("c", "c", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("c", "c", 1);
    ASSERT_TRUE( g.NumEdges() == 7 );
    weight = g.getWeight("c", "c", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("c", "d", 1);
    ASSERT_TRUE( g.NumEdges() == 8 );
    weight = g.getWeight("c", "d", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("c", "e", 1);
    ASSERT_TRUE( g.NumEdges() == 9 );
    weight = g.getWeight("c", "e", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("d", "d", 1);
    ASSERT_TRUE( g.NumEdges() == 10 );
    weight = g.getWeight("d", "d", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("d", "d", 1);
    ASSERT_TRUE( g.NumEdges() == 10 );
    weight = g.getWeight("d", "d", magnitude);
    ASSERT_TRUE(magnitude == 1);

    added = g.addEdge("d", "e", 1);
    ASSERT_TRUE( g.NumEdges() == 11 );
    weight = g.getWeight("d", "e", magnitude);
    ASSERT_TRUE(weight == 1);

    added = g.addEdge("d", "f", 1);
    ASSERT_TRUE( g.NumEdges() == 12 );
    weight = g.getWeight("d", "f", magnitude);
    ASSERT_TRUE(weight == 1);

    g.print(cout);
}

//
// test08
// This is a non-trivial test case in which I create
// a non-triival graph with 8 vertices and 12 edges and
// test my copy-constructor function in the graph.cpp file.
// I check to see if the vertex count and the edge count
// are alike, and, most importantly, check to see if the
// actual edge magnitudes and also carried over. Additionally,
// I also check to see if hte graph supports negative numbers,
// floats, and extremely large weights.
TEST(testing, copycons)
{
    graph g;

    bool added;
    bool weight;
    double magnitude;

    added = g.addVertex("a");
    added = g.addVertex("b");
    added = g.addVertex("c");
    added = g.addVertex("d");
    added = g.addVertex("e");
    added = g.addVertex("f");
    added = g.addVertex("g");
    added = g.addVertex("h");

    added = g.addEdge("a", "a", -1);
    added = g.addEdge("a", "b", 0);
    added = g.addEdge("a", "c", -10000);
    added = g.addEdge("a", "d", 4);

    added = g.addEdge("b", "a", 1234);
    added = g.addEdge("b", "b", 901);
    added = g.addEdge("b", "c", 112);
    added = g.addEdge("b", "d", 1231);

    added = g.addEdge("c", "a", 1234);
    added = g.addEdge("c", "b", 58);
    added = g.addEdge("c", "c", 148902);
    added = g.addEdge("c", "d", 8923);

    added = g.addEdge("d", "a", 18239);
    added = g.addEdge("d", "b", -0.1231);
    added = g.addEdge("d", "c", 12839.012);
    added = g.addEdge("d", "d", 123789.89);



    cout << "this is g's current num of edges: " <<
        g.NumEdges() << endl;
    // cout << "this is g1's current number of edges: " <<
    //     g1.NumEdges() << endl;
    graph g1 = g;

    ASSERT_TRUE(g1.NumVertices() == 8);
    ASSERT_TRUE(g1.NumEdges() == 16);

    cout << "This is graph g: " << endl;
    g.print(cout);

    cout << "This is graph g1: " << endl;
    g1.print(cout);

}

//
// test09
// This is a non-trivial test in which I add a million vertices and edges to the graph.
TEST(testing, test09)
{
    graph g;

    int large  =1000000;
    for ( int i = 0; i < 1000000; i++ )
    {
        g.addVertex( to_string(i) );
    }

    for ( int i = 0; i < 100000 ; i++ )
    {
        g.addEdge("0", to_string(i), 1);
    }

    ASSERT_TRUE(g.NumVertices() == 1000000);
    ASSERT_TRUE(g.NumEdges() == 100000);
}

// //
// // test08
// TEST(testing, test08)
// {
//     graph g = graph();
//     bool test1, test2, test3, test4, test5, test6, test7, test8

//     // adding vertices
//     test1=g.addVertex();
//     test2=g.addVertex();
//     test3=g.addVertex();
//     test4=g.addVertex();
//     test5=g.addVertex();
//     test6=g.addVertex();
//     test7=g.addVertex();
//     test8=g.addVertex();
//     // adding edges
// }

// //
// // test09
// TEST(testing, test09)
// {
//     graph g = graph();
//     bool test1, test2, test3, test4, test5, test6, test7, test8

//     // adding vertices
//     test1=g.addVertex();
//     test2=g.addVertex();
//     test3=g.addVertex();
//     test4=g.addVertex();
//     test5=g.addVertex();
//     test6=g.addVertex();
//     test7=g.addVertex();
//     test8=g.addVertex();
//     // adding edges
// }

// //
// // test10
// TEST(testing, test10)
// {
//     graph g = graph();

//     bool test1, test2, test3, test4, test5, test6, test7, test8
//     test1=g.addVertex();
//     test2=g.addVertex();
//     test3=g.addVertex();
//     test4=g.addVertex();
//     test5=g.addVertex();
//     test6=g.addVertex();
//     test7=g.addVertex();
//     test8=g.addVertex();

//     // adding vertices

//     // adding edges
// }

// //
// // test11
// TEST(testing, test11)
// {
//     graph g = graph();

//     bool test1, test2, test3, test4, test5, test6, test7, test8
//     // adding vertices
//     test1=g.addVertex();
//     test2=g.addVertex();
//     test3=g.addVertex();
//     test4=g.addVertex();
//     test5=g.addVertex();
//     test6=g.addVertex();
//     test7=g.addVertex();
//     test8=g.addVertex();

//     // adding edges
// }

// //
// // test12
// TEST(testing, test12)
// {
//     graph g = graph();

//     bool test1, test2, test3, test4, test5, test6, test7, test8
//     // adding vertices
//     test1=g.addVertex();
//     test2=g.addVertex();
//     test3=g.addVertex();
//     test4=g.addVertex();
//     test5=g.addVertex();
//     test6=g.addVertex();
//     test7=g.addVertex();
//     test8=g.addVertex();

//     // adding edges
// }

// //
// // test13
// TEST(testing, test13)
// {
//     graph g = graph();

//     bool test1, test2, test3, test4, test5, test6, test7, test8
//     // adding vertices
//     test1=g.addVertex();
//     test2=g.addVertex();
//     test3=g.addVertex();
//     test4=g.addVertex();
//     test5=g.addVertex();
//     test6=g.addVertex();
//     test7=g.addVertex();
//     test8=g.addVertex();

//     // adding edges
// }

// //
// // test14
// TEST(testing, test14)
// {
//     graph g = graph();

//     bool test1, test2, test3, test4, test5, test6, test7, test8
//     // adding vertices
//     g.addVertex();
//     test1=g.addVertex();
//     test2=g.addVertex();
//     test3=g.addVertex();
//     test4=g.addVertex();
//     test5=g.addVertex();
//     test6=g.addVertex();
//     test7=g.addVertex();
//     test8=g.addVertex();


//     // adding edges
// }


int main()
{
    ::testing::InitGoogleTest();

    //
    // run all the tests, returns 0 if they
    // all pass and 1 if any fail:
    //
    int result = RUN_ALL_TESTS();

    return result;
}

