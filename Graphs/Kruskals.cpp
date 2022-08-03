#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class DSU{
    int * parent;
    int* rank;
    public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == -1){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unionDSU(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            if(s1<s2){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph{
    int V;
    vector<vector<int>> edgeList;
    public:
    Graph(int v){
        this->V = v;
    }
    void addEdge(int x, int y, int w){
        edgeList.push_back({w,x,y});//we make w first so that it sorts acc to it
    }
    int kruksals_mst(){
        // 1. sort all the edges based on weight
        sort(edgeList.begin(), edgeList.end());
        int ans = 0;
        //initiate a DSU
        DSU s(V);
        //traverse through all the edges
        for(auto edge:edgeList){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            //take the edge in MST if they don't form a cycle
            int s1 = s.find(x);
            int s2 = s.find(y);
            if(s1!=s2){
                ans += w;
                s.unionDSU(s1, s2);
            }
        }
        return ans;
    }
};

int main() {
	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,3);
	g.addEdge(3,2,4);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);
	
	cout<<g.kruksals_mst()<<endl;
	return 0;
}
