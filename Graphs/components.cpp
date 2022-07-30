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
    void DFS_helper(T src, map<T, bool>& visited){
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
    int DFS_components(){
        map<T, bool> visited;
        //marking all nodes not visited in beginning
        for(auto listitem:l){
            T node = listitem.first;
            visited[node] = 0;
        }
        int ans = 0;
        for(auto x:l){
            T node = x.first;
            if(!visited[node]){
                cout<<"Component "<<ans<<" --> ";
                DFS_helper(node, visited);
                ans++;
            }
        }
        cout<<endl;
        return ans;
    }
};

int main() {
    // components
	Graph<int> g;
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	
	g.addEdge(7,8);
	
	cout<<g.DFS_components()<<endl;
	return 0;
}
