# system-programming-2-assignment-1






אכתוב באנגלית כדיי לשמור על סדר המילים
assumptions :
- all of the edges are directed
- the weight = 0 means that there is no edge

Methods:
 
- isConnected : To find strongly connected graph i am using Kosaraju's algorithm, which basiclly means finding DFS from a vertex, transposing the matrix and then finding again DFS from the same vertex, if in both ittarations all the vertecies are visited then the graph is strongly connected.

- Bellmond-Ford ; i have made a Bellmond-Ford method which does 3 things :
1) edit's a list which contains the distance from the source to each vertex
2) edit's a list which contains the previus vector from a given vertex which is on the path to the source
3) returns "false" if there was a negative cycle
this will be used for both ShortestPath and negativeCycle methods

- shortestPath : 


- negativeCycle : 