#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    vector<pair<int, int>> * l;
    public:
    Graph(int v){
        this->V = v;
        l = new vector<pair<int, int>>[V];
    }
    void addEdge(int x, int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    int prim_mst(){
        //a  min heap to store the min elements amont the added once
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        // a visited array to see if the elements are a part of the MST 
        bool * visited = new bool [V]{0};
        int ans = 0;
        //pushing the first node in the 
        Q.push({0, 0}); //{(wt, to)}
        
        while(!Q.empty()){
            auto best = Q.top();
            Q.pop();
            int weight = best.first;
            int to = best.second;
            if(visited[to]){
                //discarding the edge and moving to the next one
                continue;
            }
            //considering thie edge
            ans += weight;
            visited[to] = 1;
            
            //add all the new edges in the priority queue
            for(auto x:l[to]){
                if(visited[x.first] == 0){
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main() {
	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,3);
	g.addEdge(3,2,3);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);
	
	cout<<g.prim_mst()<<endl;
	return 0;
}
