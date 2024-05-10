//ID - 208768978
//GMAIL - michibinyamin@gmail.com

#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <stack>

using namespace std;
namespace ariel {
const int INF = INT_MAX;
// A function which calculates the transpose matrix
void trans(vector<vector<int>>& tempMatrix) {
    int size = tempMatrix.size();
    
    // Perform transpose
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i+1; j < size; j++) {  // itarate through the upper triangle
            swap(tempMatrix[i][j], tempMatrix[j][i]);
        }
    }
}

void DFS(vector<vector<int>>& tempMatrix,size_t vertex ,bool connected[]){
    int size = tempMatrix.size();
    for (size_t i = 0; i < size; i++)
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
    for (size_t i = 0; i < size; i++)
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
bool Algorithms::isConnected(const Graph& g) {
    vector<vector<int>> tempMatrix = g.getg();  // For editing copyd graph
    int size = tempMatrix.size();
    bool connected[size];

    CheckAndReset(connected, size); // For initializing all elements to false
    DFS(tempMatrix, 0, connected);  // Check DFS from first point

    if (!CheckAndReset(connected, size)) // Checks if all are true + resets all to false
    {
        return false;
    }

    trans(tempMatrix);  // Transpose the matrix
    DFS(tempMatrix, 0, connected);  // Check again DFS from first point
    if (!CheckAndReset(connected, size)) // Checks if all are true + resets all to false
    {
        return false;
    }
    return true;
}



// Function to implement Bellman-Ford algorithm
bool bellmanFord(vector<vector<int>>& graph, int source, vector<int>& dist, vector<int>& pred) {
    size_t size = graph.size();
    dist.assign(size, INF); // A list which contains the distance from the source to each vertex
    pred.assign(size, -1);  // A list which contains the previus vector from the source
    dist[source] = 0;   // Initialize the source distance to 0

    // The maximum amount of times needed in bellmond-ford
    for (size_t i = 0; i < size-1; ++i)
    {
        // Itarate throgh the matrix : 
        for (size_t u = 0; u < size; u++)
        {
            for (size_t v = 0; v < size; v++)
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
    for (size_t u = 0; u < size; u++) {
        for (size_t v = 0; v < size; v++) {
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

    // check for negative cycle on the path
    if (no_negative_cycle)
    {
        // If the end vertex is -1 then there is no path
        if(pred[end] == -1){
            return "-1";
        }
        string path = to_string(end);   // Add the end to the string
        for (size_t i = 0; i < pred.size(); i++)
        {
            path = to_string(pred[end])+"->"+path;  // Add another vertex to the string
            end = pred[end];
            if(end == start){
                return path;
            }   
        }
    }
    return "-1";
}

string isContainsCycleDFC(vector<vector<int>> g, int t, vector<int>& visited, vector<int>& cycle_stack) {
    // Mark the current vertex as investigating - grey
    visited[t] = 1;
    cycle_stack.push_back(t);

    for (size_t i = 0; i < g.size(); i++)
    {
        if (g[t][i] != 0) // 0 means there is no path, makes sure it also has not been visited
        {
            // If not visited vertex
            if(visited[i] != 2){
                // Check for back edge
                if (visited[i] == 1)
                {
                    // print the vertecies who are in the cycle by poping them out all the way back to the start
                    string route = to_string(i);
                    while (cycle_stack.back()!=i)
                    {
                        route = to_string(cycle_stack.back())+"->"+route;
                        cycle_stack.pop_back();
                    }
                    route = to_string(i) +"->"+route;
                    return route;
                }
                // else case - it is white : 
                string route = isContainsCycleDFC(g, i, visited, cycle_stack);
                // Call on the connected vertex
                if (route!="0") 
                {
                    return route;
                }  
            } 
        }
    }
    // Remove the current vertex from the recursion stack as we backtrack
    visited[t] = 2; // Vertex black
    cycle_stack.pop_back(); // Remove element from stack
    return "0";
}

// Function to check if the graph contains a cycle
string Algorithms::isContainsCycle(const Graph& g) {
    vector<vector<int>> graph = g.getg();
    int n = graph.size();
    // 0 - white, 1 - grey, 2 - black
    vector<int> visited(n, 0);
    
    // Perform DFS from each unvisited node
    for (size_t i = 0; i < n; i++) {
        vector<int> cycle_stack;
        if (visited[i] == 0) {
            string path = isContainsCycleDFC(graph, i, visited, cycle_stack);
            if (path != "0")
            {
                return path;
            }
        }
    }
    // No cycle detected
    return "0";
}

bool isBipartiteDFS(vector<vector<int>>& graph, int current, vector<int>& visited, vector<int>& group_A, vector<int>& group_B, int group_num){
    // numbers for dividing into two groups
    visited[current] = group_num;    // Mark group
    // Add to the correct group
    if (group_num == 0)
    {
        group_A.push_back(current);
    }
    else{
        group_B.push_back(current);
    }

    for (size_t i = 0; i < graph.size(); i++)
    {
        if (graph[current][i]!=0)
        {
            if (visited[i]==-1) // Has not been visited
            {
                if (!isBipartiteDFS(graph, i, visited, group_A, group_B, 1-group_num)) {
                    return false; // If any recursive DFS call returns false, the graph is not bipartite
                }
            }
            else if (visited[i]==visited[current])  // Has the same color as the neighbor
            {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the graph is bipartite
string Algorithms::isBipartite(const Graph& g) {
    vector<vector<int>> graph = g.getg();
    // Turn graph to an undirected graph so we can do dfs coloring (i will put wights - 1 becuase we dont care)
    // If there is a directed edge from one to another then make a directed edge back. we can find the bipartite 
    // on this graph and that will include the original directed graph.
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph.size(); j++)
        {
            if (graph[i][j]!=0 || graph[j][i]!=0)
            {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    vector<int> group_A;
    vector<int> group_B;
    vector<int> visited(graph.size(), -1);
    // Use dfs to traverse throgh neighbors
    for (size_t i = 0; i < graph.size(); i++)
    {
        if (visited[i] == -1) {
            if (!isBipartiteDFS(graph, i, visited, group_A, group_B, 0)){
                // graph is not bipertite
                return "0";
            }
        }
    }
    
    string groups = "The graph is bipartite: A={";
    for (size_t i = 0; i < group_A.size(); i++)
    {
        groups = groups + to_string(group_A[i]);
        if (i < group_A.size() - 1) {
        groups += ",";
        }
    }
    groups = groups + "}, B={";
    for (size_t i = 0; i < group_B.size(); i++)
    {
        groups = groups + to_string(group_B[i]);
        if (i < group_B.size() - 1) {
        groups += ",";
        }
    }
    groups = groups + "}";
    return groups;
}

// Function to find a negative cycle in the graph
string Algorithms::negativeCycle(const Graph& g) {
    vector<vector<int>> graph = g.getg();

    // Create a new vertex which connects to all the rest, so that we can find over all the grapgh for cycles
    vector<vector<int>> graph_with_new_v(graph.size()+1, vector<int>(graph.size()+1, 0));
    for (size_t i = 0; i < graph.size()+1; i++)
    {
        for (size_t j = 1; j < graph.size()+1; j++)
        {
            if (i==0){
                graph_with_new_v[i][j] = 1;
            }
            else{
                graph_with_new_v[i][j] = graph[i-1][j-1];
            }
        }
    }
        
    vector<int> dist;
    vector<int> pred;
    // Call bellmond-ford method
    bool no_negative_cycle = bellmanFord(graph_with_new_v, 0, dist, pred);   // Call bellmanFord on first vertex
    if (no_negative_cycle)
    {
        return "No negative cycle";
    }

    int vertex; // This will store a vertex which we found in the negative cycle so we can trace it back
    // Relaxation to find a vertex which is inside the negative cycle
    for (size_t u = 0; u < dist.size(); u++) {
        for (size_t v = 0; v < dist.size(); v++) {
            int weight = graph_with_new_v[u][v];
            if (weight != 0 && dist[u] != INF && dist[u] + weight < dist[v]) {
                pred[v] = u;    // Added for tracing it back
                vertex = u;
            }           
        }
    }
    // Now we will trace it back untill we get back to the same point and then print (we do -1 becuse the matrix is bigger with the extra vertex)
    int trace = vertex;
    string path = to_string(vertex-1);   // Add the trace to the string
    for (size_t i = 0; i < pred.size(); i++)
    {
        path = to_string(pred[trace]-1)+"->"+path;  // Add another trace to the string.
        trace = pred[trace];
        if(trace == vertex){
            return "negative cycle found : " + path;
        }
    }
    return "No negative cycle";
}

} // namespace ariel
