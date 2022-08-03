#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <set>
#include <climits>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T, list<pair<T, int>>> h;
    
    public:
    void addEdge(T u, T v, int dist, bool bidir = true){
        h[u].push_back(make_pair(v,dist));
        if(bidir){
            h[v].push_back(make_pair(u, dist));
        }
    }
    void printAdj(){
        //iterating over all the key value pairs in the map
        for(auto x:h){
            T node = x.first;
            auto cityList = x.second;
            cout<<node<<" --> ";
            for(auto y:cityList){
                cout<<" ("<<y.first<<","<<y.second<<")";
            }
            cout<<endl;
        }
    }
    void Dijkstras(T src){
        //creating the dist map
        unordered_map<T, int> dist;
        //set all dist to inf
        for(auto j:h){
            dist[j.first] = INT_MAX;
        }
        dist[src] = 0;
        
        //making a set to find out node with the min distance
        set <pair<int, T>> s;
        s.insert(make_pair(0, src));
        
        while(!s.empty()){
            //taking the pair at the front
            auto p = *(s.begin());
            
            T node = p.second;
            int nodeDist = p.first;
            
            s.erase(s.begin());
            
            //iterating over the neighbours of the current node
            for(auto childPair:h[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    T dest = childPair.first;
                    //in the set updation is not possible
                    //so we remove the old pair and insert a new pair
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    //inserting a new pair in the set
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        //printing distances to all other nodes from the src
        for(auto d:dist){
            cout<<d.first<<" is located at a distance of "<<d.second<<endl;
        }
    }
};

int main() {
	// Dijkstras Algorithm
	Graph <string> india;
	india.addEdge("Amritsar", "Delhi", 1);
	india.addEdge("Amritsar", "Jaipur", 4);
	india.addEdge("Jaipur", "Delhi", 2);
	india.addEdge("Jaipur", "Mumbai", 8);
	india.addEdge("Bhopal", "Agra", 2);
	india.addEdge("Mumbai", "Bhopal", 3);
	india.addEdge("Delhi", "Agra", 1);
	
	india.printAdj();
	
	india.Dijkstras("Amritsar");
	
	return 0;
}
