#include <iostream>
#include <list>
using namespace std;
class Graph{
    int v;
    list<int> * l;
    public:
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }
    void addNode(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjList(){
        for(int i=0; i<v; i++){
            cout<<"Vertex :"<<i<<endl;
            cout<<"Neighbours :";
            for(auto element:l[i]){
                cout<<element<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
	// implementation Graphs
	Graph g(4);
	g.addNode(0,1);
	g.addNode(0,2);
	g.addNode(1,2);
	g.addNode(2,3);
	g.printAdjList();
	return 0;
}
