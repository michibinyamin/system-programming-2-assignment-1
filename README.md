# system-programming-2-assignment-1

אכתוב באנגלית כדיי לשמור על סדר המילים וכי זה יותר נוח לי

**assumptions :**
- I am assuming that all of the edges are directed, why? becuese when i am given a adjacency matrix, i dont have a way to know if a given edge is an undirected edge of weight - k or is it two directed edges from one to another with both wieghts - k, so here an undirected matrix can be looked as a "special case" of the directed matrix.

- the weight = 0 means that there is no edge(usually it is infinity, but we where asked for it to be 0 in this assignment)


**Method implimentations :**
 
- Bellmond-Ford ; i have made a Bellmond-Ford method which does 3 things :
1) edit's a list which contains the distance from the source to each vertex
2) edit's a list which contains the previus vector from a given vertex which is on the shortest path to the source vertex
3) returns "false" if there was a negative cycle
this will be used for both ShortestPath and negativeCycle methods.

- isConnected : To find strongly connected graph i am using Kosaraju's algorithm, which basiclly means finding DFS from a vertex, transposing the matrix and then finding again DFS from that same vertex, if in both ittarations all the vertecies are visited then the graph is strongly connected.

- shortestPath : this method uses the Bellmond-Ford method to find the shortest path between two vertecies, it first makes sure there
are no negative cycles on the path, and if not it tracks back the route from the last node to the start node with the prev list, if there is no such rute or negative cycles on its way then it returns -1
else it returns the path

- isContainsCycle : to find if the graph contains a cycle it set 3 colors: white, grey and black as 0, 1 ,2 and i ran DFS on the graph to see if i find a back edge(while an itaration of a vertex stumbling on a grey vertex) if this is the case, return that there is a cycle(and i usesd a stack to retrive the nodes in the cycle)

- isBipartite : the idea in my algorithm is to traverse with DFS throgh the tree and color each node with one of two colors.
use a color to color the current node and then color all its neighbors with the opposite color, if we stumble accross a neighbor which has the same color as the current node then the graph cannot be bipartite. else the two groups of colors are the groups the of the bipartite. 
note! i turned the graph to an undirected graph just for making it easier to handle, this does not affect the final result, and works the same!

- negativeCycle : uses Bellmon-Ford to detect if there is a negative cycle, notice! i added an extra vertex on the beggining which will have edges of
weight one pointing to all of the othor vertecies. this was done by just adding an extra point in the matrix accourdanly.
if there is a negative cycle after running bellmonf-ford then the algorithem does one more relaxasation and finds the vertex which increases its distance while that relaxation. 
from that vertex it traces back the vertecies with the prev list to find the path of the cycle untill it returns to the same vertex then it stops and returns the result.
if there were no negative cycles then it returns "no negative cycle"



**in addition :**

- i created a function in the main program which handles all of the printing for each matrix, this way you can create a new matrix and just call the function to print.

- i have added many more tests to check for my algorithms, including self-edges.

- in the algorithms.hpp file i have created a private constructor, this way no one can create an object from algorithms

- in the graph.hpp i made a empty default constructor becuase the matrix is initialized in the loadGraph

END



