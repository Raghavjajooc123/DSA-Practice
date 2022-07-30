#include <iostream>
#include <map>
#include <queue>
#include <climits>
#include <list>
using namespace std;
template<typename T>
class Graph{
    map<T, list<T>> l;
    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void DFS_helper(T src, map<T, bool> visited){
        //recursive function to traverse the Graph
        cout<<src<<" ";
        visited[src] = 1;
        //go to all nbrs and check for visited
        for(auto node:l[src]){
            if(!visited[node]){
                DFS_helper(node, visited);
            }
        }
    }
    void DFS(T src){
        map<T, bool> visited;
        //marking all nodes not visited in beginning
        for(auto listitem:l){
            T node = listitem.first;
            visited[node] = 0;
        }
        DFS_helper(src, visited);
    }
};

int main() {
    // DFS in Graph
	Graph<int> g;
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	
	g.DFS(0);
	return 0;
}
