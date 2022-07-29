#include <iostream>
#include <map>
#include <queue>
#include <climits>
#include <list>
using namespace std;
class Graph{
    map<int, list<int>> l;
    public:
    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    void BFS(int src, int target){
        queue<int> q;
        map<int, int> dist;
        map<int, int> parent; // used to get the path
        for(auto listPair:l){
            int node = listPair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr:l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                    parent[nbr] = node;
                }
            }
        }
        int temp = target;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;
        cout<<dist[target]<<endl;
    }
};

int main() {
	// Snakes and ladders problem
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[35] = -22;
	
	//adding all edges to graph
	Graph g;
	for(int i=0; i<=36; i++){
	    for(int dice=1; dice<=6; dice++){
	        int j = i+dice;
	        j+=board[j];
	        if(j<=36){
	            g.addEdge(i,j);
	        }
	    }
	}
	g.addEdge(36,36);
	g.BFS(0, 36);
	return 0;
}
