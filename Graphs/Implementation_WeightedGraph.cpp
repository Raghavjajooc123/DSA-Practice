#include <iostream>
#include <unordered_map>
#include <cstring>
#include <list>
using namespace std;
class Graph{
    unordered_map<string, list<pair<string, int>>> l;
    public:
    void addEdge(string src, string dest, bool isAdj, int weight){
        l[src].push_back(make_pair(dest, weight));
        if(isAdj){
            l[dest].push_back(make_pair(src, weight));
        }
    }
    void print(){
        for(auto p:l){
            string city = p.first;
            list<pair<string, int>> neighbours = p.second;
            cout<<"City : "<<city<<endl<<" Neighbours : ";
            for(pair city:neighbours){
                cout<<"City "<<city.first<<" at a distance "<<city.second<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
	// weighted graph uni and bidirectional
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("A", "C", true, 10);
	g.addEdge("B", "D", true, 40);
	g.addEdge("C", "D", true, 30);
	g.addEdge("A", "D", false, 50);
	g.print();
	return 0;
}
