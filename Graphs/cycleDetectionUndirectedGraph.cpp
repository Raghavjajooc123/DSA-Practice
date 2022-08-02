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
        //directed graph
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    bool cycleHelper(int node, bool * visited, int parent){
        visited[node] = 1;
        for(int nbr:l[node]){
            //nbr visited but not equal to parent
            if(visited[nbr] == 1 && nbr!=parent){
                return true;
            }
            //unvisited nbr, we will visit recursively
            else if(visited[nbr]!= 1){
                bool cyclePresent = cycleHelper(nbr, visited, node);
                if(cyclePresent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool cycleDetectionUndirected(){
        bool * visited = new bool[v];
        
        for(int i=0; i<v; i++){
            visited[i] = 0;
        }
        
        return cycleHelper(0, visited, -1);
    }
};

int main() {
	// directed graph cycle detection
	Graph g(5);
	g.addNode(0,1);
	g.addNode(1,2);
	g.addNode(2,3);
	g.addNode(3,4);
	g.addNode(4,0);
	
	cout<<g.cycleDetectionUndirected()<<endl;
	return 0;
}
