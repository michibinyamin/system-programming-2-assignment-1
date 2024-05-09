//ID - 208768978
//GMAIL - michibinyamin@gmail.com

/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void print_stats(Graph& g, int start, int end){
    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    if (Algorithms::isConnected(g) == 1)
    {
        cout << "Graph is connected\n";
    }
    else{
        cout << "Graph not connected\n";
    }

    string path = Algorithms::shortestPath(g, start, end);        // Should print: "1" (true).
    if (path != "-1")
    {
        cout << "Shortest path from " + to_string(start) + " to " + to_string(end) + " is: " + path + "\n";
    }
    else{
        cout << "there is no shortest path from "+to_string(start)+" to "+to_string(end)+"\n";
    }


    string cycle = Algorithms::isContainsCycle(g);        // Should print: "1" (true).
    if (cycle != "0")
    {
        cout << "cycle found: "+cycle+"\n";
    }
    else{
        cout << "no cycles found\n";
    }


    string groups = Algorithms::isBipartite(g);        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    if (groups != "0")
    {
        cout << groups + "\n";
    }
    else{
        cout << "The graph is not bipartite\n";
    }
    cout << Algorithms::negativeCycle(g) << endl;
    cout << "\n";
}

int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, -2, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.
    print_stats(g, 0, 2);  // Pass also the vertecies for the shortest path

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.
    print_stats(g, 0, 4);  // Pass also the vertecies for the shortest path

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 4, 0},
        {0, 0, 0, 0, -5},
        {0, 0, 0, 2, 0}};
    g.loadGraph(graph3); // Load the graph to the object.
    print_stats(g, 0, 4);  // Pass also the vertecies for the shortest path

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph4 = {
        {0, 0, 5, 0, 0},
        {1, 0, 0, 3, 0},
        {1, 0, 0, 4, 0},
        {0, 4, 0, 0, 1},
        {0, 0, 0, 2, 0}};
    g.loadGraph(graph4); // Load the graph to the object.
    print_stats(g, 0, 4);  // Pass also the vertecies for the shortest path

    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph5 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph5); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
}
