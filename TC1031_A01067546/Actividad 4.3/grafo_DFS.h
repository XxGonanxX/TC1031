#include <iostream> 
#include <list> 
using namespace std; 
//graph class for DFS travesal  
class DFSGraph 
{ 
int V;    // No. of vertices 
list<string> *adjList;    // adjacency list 
void DFS_util(int v, bool visited[]);  // A function used by DFS 
public: 
    // class Constructor
DFSGraph(int V)
    {
 this->V = V; 
 adjList = new list<string>[V]; 
    }
    // function to add an edge to graph 
void addEdge(int v, string w){
adjList[v].push_back(w); // Add w to v’s list.
    }
     
void DFS();    // DFS traversal function 
}; 
void DFSGraph::DFS_util(int v, bool visited[]) 
{ 
    // current node v is visited 
visited[v] = true; 
cout << v << " "; 
   
    // recursively process all the adjacent vertices of the node 
while(adjList[v].begin() != adjList[v].end()) 
DFS_util(v, visited); 
} 
   
// DFS traversal 
void DFSGraph::DFS() 
{ 
    // initially none of the vertices are visited 
bool *visited = new bool[V]; 
for (int i = 0; i < V; i++) 
visited[i] = false; 
   
    // explore the vertices one by one by recursively calling  DFS_util
for (int i = 0; i < V; i++) 
if (visited[i] == false) 
DFS_util(i, visited); 
} 
   
int main() 
{ 
    // Create a graph
DFSGraph gdfs(5); 
gdfs.addEdge(0, "Hola"); 

 
cout << "Depth-first traversal for the given graph:"<<endl; 
gdfs.DFS(); 
return 0;
}