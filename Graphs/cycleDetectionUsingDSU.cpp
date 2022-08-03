#include <iostream>
#include <list>
using namespace std;
class Graph{
    int V;
    //edge list representation {(2,3), (0,1).......}
    list<pair<int, int>> l;
    public:
    Graph(int v){
        this->V = v;
    }
    void addEdge(int a, int b){
        l.push_back(make_pair(a,b));
    }
    //find function
    int findSet(int i, int parent[]){
        if(parent[i] == -1){
            return i;
        }
        return findSet(parent[i], parent);
    }
    //union set
    void unionSet(int x, int y, int parent[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if(s1!=s2){
            parent[s2] = s1;
        }
        return;
    }
    bool contains_cycle(){
        //DSU Logic to check if graph containg cycle or not
        int * parent = new int[V];
        for(int i=0; i<V; i++){
            parent[i] = -1;
        }
        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);
            
            if(s1!=s2){
                unionSet(s1, s2, parent);
            }
            else{
                return true;
            }
        }
        delete [] parent;
        return false;
    }
};

int main() {
	// cycle detection using DSU
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
// 	g.addEdge(3,0);
	
	cout<<g.contains_cycle()<<endl;
	return 0;
}
