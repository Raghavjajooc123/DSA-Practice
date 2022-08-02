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
    }
    bool cycleHelper(int node, bool* visited, bool* stack){
        //visiting a node
        visited[node] = 1;
        stack[node] = 1;
        
        //check if that node contains a cycle 
        for(int nbr : l[node]){
            if(stack[nbr]){
                return true;
            }
            else if(visited[nbr] == false){
                bool cycleFoundAhead = cycleHelper(nbr, visited, stack);
                if(cycleFoundAhead){
                    return true;
                }
            }
        }
        //leaving a node
        stack[node] = false;
        return false;
    }
    bool cycleDetectionDirected(){
        bool * visited = new bool[v];
        bool * stack = new bool[v];
        
        for(int i=0; i<v; i++){
            visited[i] = stack[i] = 0;
        }
        
        return cycleHelper(0, visited, stack);
    }
};

int main() {
	// directed graph cycle detection
	Graph g(7);
	g.addNode(0,1);
	g.addNode(1,2);
	g.addNode(2,3);
	g.addNode(3,4);
	g.addNode(4,5);
	g.addNode(1,5);
	g.addNode(5,6);
	g.addNode(4,2);//back edge
	
	cout<<g.cycleDetectionDirected()<<endl;
	return 0;
}
