#include "Graph.hpp"
#include <iostream>
// Namespaces and includes are in the header file
using namespace std;

namespace ariel{

vector<vector<int>> adjMatrix;

    // Function to load the graph from a given input
    void Graph::loadGraph(const vector<vector<int>>& inputMatrix) {
        // Check if the matrix is square
        int rows = inputMatrix.size(); // Number of rows
        for (const auto& row : inputMatrix) {
            // If the length of any row doesnt match the number of rows
            if (row.size() != rows) {
                throw invalid_argument("Matrix must be square (n by n).");
            }
        }
        adjMatrix = inputMatrix;
    }

    // Function to print the graph's adjacency matrix
    void Graph::printGraph() const {
        for (const auto& row : adjMatrix) {
            for (int value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
    
    // Function to access the adjacency matrix
    const vector<vector<int>>& Graph::getg() const {
        return adjMatrix;
    }
}


