// If this HPP file was defined, then it prevents it from being defind twice.
// If it was not defined then it definds it. 
// Can also use pragme1
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
using namespace std;
namespace ariel {
class Graph {
    vector<vector<int>> adjMatrix;
public:
    Graph();  // Constructor
    // Function to load the graph from a given input
    void loadGraph(const vector<vector<int>>& inputMatrix);
    
    // Function to print the graph's adjacency matrix
    void printGraph() const;


    // Function to access the adjacency matrix
    const vector<vector<int>>& getg() const;
};
}
#endif