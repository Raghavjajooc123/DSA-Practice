#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int v;
    list<int> *l;
    public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addNode(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool is_tree(){
        bool * visited = new bool[v];
        int * parent = new int[v];
        
        queue<int> q;
        
        for(int i=0; i<v; i++){
            visited[i] = 0;
            parent[i] = i;
        }
        
        int src = 0;
        q.push(src);
        visited[src] = 1;
        
        //pop out one node and visit its neighbours
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr:l[node]){
                if(visited[nbr] == 1 && nbr != parent[node]){
                    return false;
                }
                else if(!visited[nbr]){
                    visited[nbr] = 1;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};

int main() {
	// undirected graph is tree or not
	Graph g(4);
	g.addNode(0,1);
	g.addNode(3,2);
	g.addNode(1,2);
// 	g.addNode(0,3);
	cout<<g.is_tree()<<endl;
	return 0;
}
