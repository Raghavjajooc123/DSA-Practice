#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <list>
using namespace std;
template<typename T>
class Graph{
    map<T, list<T>> l;
    public:
    void addNode(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print(){
        for(pair p:l){
            cout<<p.first<<" Neighbours : ";
            for(auto nbr:p.second){
                cout<<nbr<<" ";
            }
            cout<<endl;
        }
    }
    void printBFS(T node){
        queue<T> q;
        map <T,bool> visited;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
    }
};

int main() {
	// weighted graph uni and bidirectional
	Graph<int> g;
	g.addNode(0,1);
	g.addNode(1,2);
	g.addNode(2,3);
	g.addNode(3,4);
	g.addNode(4,5);
	g.addNode(0,3);
	g.print();
	g.printBFS(0);
	return 0;
}
