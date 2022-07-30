#include <iostream>
#include <list>
#include <queue>
using namespace std;
class Graph{
    list<int> * l;
    int v;
    public:
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    void topological_sort(){
        //indegree
        int * indegree = new int[v];
        for(int i=0; i<v; i++){
            indegree[i] = 0;
        }
        //update indegree by traversing degree
        for(int i=0; i<v; i++){
            for(auto y:l[i]){
                indegree[y]++;
            }
        }
        //bfs here
        queue<int> q;
        //finding nodes with zero indegree
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        //rempving elements from the queue
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            //iterate over neighbours and reduce their indegree
            for(auto nbr:l[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
};
int main() {
	// topological sort bfs
	Graph g(6);
	
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(0,2);
	g.addEdge(4,5);
	
	g.topological_sort();
	return 0;
}
