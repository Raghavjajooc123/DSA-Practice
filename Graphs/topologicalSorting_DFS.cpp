#include <iostream>
#include <map>
#include <cstring>
#include <list>
using namespace std;
template<typename T>
class Graph{
    map<T, list<T>> l;
    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
    }
    void DFS_helper(T src, map<T, bool>& visited, list<T>& instructions){
        //recursive function to traverse the Graph
        visited[src] = 1;
        //go to all nbrs and check for visited
        for(auto node:l[src]){
            if(!visited[node]){
                DFS_helper(node, visited, instructions);
            }
        }
        instructions.push_front(src);
    }
    void DFS_TopologicalSorting(){
        map<T, bool> visited;
        list<T> instructions;
        //marking all nodes not visited in beginning
        for(auto listitem:l){
            T node = listitem.first;
            visited[node] = 0;
        }
        
        for(auto x:l){
            T node = x.first;
            if(!visited[node]){
                DFS_helper(node, visited, instructions);
            }
        }
        
        for(auto node:instructions){
            cout<<node<<" --> ";
        }
        return;
    }
};

int main() {
    // DFS topological sorting
	Graph<string> g;
	
	g.addEdge("Python","Data Processing");
	g.addEdge("Python","PyTorch");
	g.addEdge("Python","ML Basics");
	g.addEdge("PyTorch","Deep Learning");
	g.addEdge("Data Processing","ML Basics");
	g.addEdge("ML Basics","Deep Learning");
	g.addEdge("Dataset","Face Recognation");
	g.addEdge("Deep Learning","Face Recognation");
	
	g.DFS_TopologicalSorting();
	return 0;
}
