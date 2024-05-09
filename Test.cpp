//ID - 208768978
//GMAIL - michibinyamin@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 6},
        {1, 1, 0, 1, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 8, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

        vector<vector<int>> graph4 = {
        {0, 0, -1, 0, 0},
        {0, 0, 4, 0, 0},
        {1, 0, 0, 0, 8},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);

        vector<vector<int>> graph5 = {
        {0, 1},
        {-1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == true);

}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

        vector<vector<int>> graph2 = {
        {0, 1, 4},
        {1, 0, 2},
        {0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 6},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->2->3->4");

        vector<vector<int>> graph4 = {  // Here there is -6 instead of 6
        {0, 1, 1, 0, -6},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->4");

        vector<vector<int>> graph5 = {  // Here there is a negative cycle
        {0, 1, 1, 0, -6},
        {1, 0, 1, 0, 0},
        {1, -4, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "1->2->3->1");

        vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

        vector<vector<int>> graph5 = {
        {0, 0, 0, 0, 3},
        {5, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, -1, 0, 0, 0},
        {0, 0, -3, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->4->2->3->1->0");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 1, 0},
        {0, 0, 0, 4, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {1, 0, -1},
        {0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    vector<vector<int>> graph3 = {
        {0, 0, 0},
        {1, 0, -1},
        {0, -1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "negative cycle found : 1->2->1");

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {-6, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "negative cycle found : 0->2->0");

    vector<vector<int>> graph5 = {
        {0, -1, 0, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, -1, 0},
        {0, 0, 1, 0, -1},
        {-1, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "negative cycle found : 0->1->2->3->4->0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {
        {0, 1, 2, 0, 3},
        {1, 0, 3, 0, 2},
        {2, 3, 0, 4, 1},
        {0, 0, 4, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph2));
}

// And more tests to check diffarent types of matricies : 

TEST_CASE("Test empty graph")
{
    ariel::Graph g;
    vector<vector<int>> emptyGraph = {};
    g.loadGraph(emptyGraph);

    // An empty graph should not contain any cycles
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    // An empty graph is trivially bipartite
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={}, B={}");

    // There are no negative cycles in an empty graph
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    // There is connectivity in an empty graph
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test graph with self-loops")
{
    ariel::Graph g;
    vector<vector<int>> graphWithSelfLoops = {
        {1, 1, 0},
        {0, -1, 2},
        {0, 2, 1}};
    g.loadGraph(graphWithSelfLoops);

    // Self loops are cycles
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->0");

    // Self loops make the same vertex inside the same group color
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Self loops can introduce negative cycles if weights are negative
    CHECK(ariel::Algorithms::negativeCycle(g) == "negative cycle found : 1->1");

    // There is no way from vertex 2 to vertex 0
    CHECK(ariel::Algorithms::isConnected(g) == false);
}


