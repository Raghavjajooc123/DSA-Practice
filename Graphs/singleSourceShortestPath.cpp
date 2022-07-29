#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <list>
#include <climits>
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
    void printBFSLevels(T src){
        queue<T> q;
        map <T, int> dist;
        for(auto node_pair:l){
            T temp = node_pair.first;
            dist[temp] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto nbr:l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                }
            }
        }
        //printing the BFS Levels
        for(auto x:l){
            T node = x.first;
            int distance = dist[node];
            cout<<"Node "<<node<<" at a distance of "<<distance<<endl;
        }
    }
};

int main() {
	// single source shortest path
	Graph<int> g;
	g.addNode(0,1);
	g.addNode(1,2);
	g.addNode(2,3);
	g.addNode(3,4);
	g.addNode(4,5);
	g.addNode(0,3);
	g.print();
	g.printBFSLevels(0);
	return 0;
}
