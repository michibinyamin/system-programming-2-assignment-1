#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;
namespace ariel {
const int INF = INT_MAX;
// A function which calculates the transpose matrix
void trans(vector<vector<int>>& tempMatrix) {
    int size = tempMatrix.size();
    
    // Perform transpose
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {  // itarate through the upper triangle
            swap(tempMatrix[i][j], tempMatrix[j][i]);
        }
    }
}

void DFS(vector<vector<int>>& tempMatrix,int vertex ,bool connected[]){
    int size = tempMatrix.size();
    for (int i = 0; i < size; i++)
    {
        if (tempMatrix[vertex][i] != 0 && !connected[i]) // 0 means there is no path, makes sure it also has not been visited
        {
            connected[i] = true;    // There is a connection
            DFS(tempMatrix, i, connected);  // Call on the connected vertex
        }
    }
}

// Function which does both reseting the array to false and checks if all is true before reseting
bool CheckAndReset(bool connected[], int size){
    bool b = true;
    for (int i = 0; i < size; i++)
    {
        if (!connected[i])
        {
            b = false;
        }
        connected[i] = false;
    }
    return b;   // if there is at least 1 false in the list it will return false, else true
}

// Function to check if the graph is connected
int Algorithms::isConnected(const Graph& g) {
    vector<vector<int>> tempMatrix = g.getg();  // For editing copyd graph
    int size = tempMatrix.size();
    bool connected[size];

    CheckAndReset(connected, size); // For initializing all elements to false
    DFS(tempMatrix, 0, connected);  // Check DFS from first point

    if (!CheckAndReset(connected, size)) // Checks if all are true + resets all to false
    {
        return 0;
    }

    trans(tempMatrix);  // Transpose the matrix
    DFS(tempMatrix, 0, connected);  // Check again DFS from first point
    if (!CheckAndReset(connected, size)) // Checks if all are true + resets all to false
    {
        return 0;
    }
    return 1;
}



// Function to implement Bellman-Ford algorithm
bool bellmanFord(vector<vector<int>>& graph, int source, vector<int>& dist, vector<int>& pred) {
    int size = graph.size();
    dist.assign(size, INF); // A list which contains the distance from the source to each vertex
    pred.assign(size, -1);  // A list which contains the previus vector from the source
    dist[source] = 0;   // Initialize the source distance to 0

    // The maximum amount of times needed in bellmond-ford
    for (int i = 0; i < size-1; i++)
    {
        // Itarate throgh the matrix : 
        for (int u = 0; u < size; u++)
        {
            for (int v = 0; v < size; v++)
            {
                // Relaxation step on a given edge
                int weight = graph[u][v];
                if (weight != 0 && dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pred[v] = u;
                }
            }
        }
    }
    // Check for negative weight cycles
    for (int u = 0; u < size; u++) {
        for (int v = 0; v < size; v++) {
            int weight = graph[u][v];
            if (weight != 0 && dist[u] != INF && dist[u] + weight < dist[v]) {
                return false; // Negative cycle found
            }
        }
    }
    return true;
}

// Function to find the shortest path in the graph
string Algorithms::shortestPath(const Graph& g, int start, int end) {
    vector<vector<int>> graph = g.getg();
    vector<int> dist;
    vector<int> pred;
    bool no_negative_cycle = bellmanFord(graph, start, dist, pred);   // Call bellmanFord

    // check for negative cycle
    if (no_negative_cycle)
    {
        // If the end vertex is not -1 then there is a path
        if(pred[end] == -1){    
            return "-1";
        }
        string path = to_string(end);   // Add the end to the string
        for (int i = 0; i < pred.size(); i++)
        {
            path = to_string(pred[end])+"->"+path;  // Add another vertex to the string
            end = pred[end];
            if(end == start){
                return path;
            }   
        }
    }
    return "";
}

// Function to check if the graph contains a cycle
int Algorithms::isContainsCycle(const Graph& g) {
    return 1;
    // Function implementation goes here
}

// Function to check if the graph is bipartite
string Algorithms::isBipartite(const Graph& g) {
    return "1";
    // Function implementation goes here
}

// Function to find a negative cycle in the graph
void Algorithms::negativeCycle(const Graph& g) {
    vector<vector<int>> graph = g.getg();
    vector<int> dist;
    vector<int> pred;
    // Call bellmond-ford method
    bool no_negative_cycle = bellmanFord(graph, 0, dist, pred);   // Call bellmanFord on first vertex
    if (no_negative_cycle)
    {
        cout << "No negative cycle";
        return;
    }

    int vertex; // This will store a vertex which we found in the negative cycle so we can trace it back
    // Relaxation to find a vertex which is inside the negative cycle
    for (int u = 0; u < dist.size(); u++) {
        for (int v = 0; v < dist.size(); v++) {
            int weight = graph[u][v];
            if (weight != 0 && dist[u] != INF && dist[u] + weight < dist[v]) {
                pred[v] = u;    // Added for tracing it back
                vertex = u;
            }           
        }
    }
    // Now we will trace it back untill we get back to the same point and then print
    int trace = vertex;
    string path = to_string(vertex);   // Add the trace to the string
    for (int i = 0; i < pred.size(); i++)
    {
        path = to_string(pred[trace])+"->"+path;  // Add another trace to the string
        trace = pred[trace];
        if(trace == vertex){
            cout << path;
            return;
        }
    }
}

} // namespace ariel
