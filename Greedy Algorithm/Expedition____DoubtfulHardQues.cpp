#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
bool townDistanceCompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first<p2.first;
}
int min_stations(pair<int, int>* stations, int n, int l, int p){
    for(int i=0; i<n; i++){
        stations[i].first = p - stations[i].first;
    }
    sort(stations, stations+n, townDistanceCompare);
    
    int ans = 0;
    int prev = 0;
    priority_queue<int> fuels;
    int x = 0; //the current city
    
    while(x<n){
        //if we have enough fuel to go to the next city
        if(p >= stations[x].first - prev){
            p = p - (stations[x].first - prev);
            fuels.push(stations[x].second);
            prev = stations[x].first;
        }
        else{
            if(fuels.empty()){
                return -1;
            }
            else{
                //refulling occurs
                p += fuels.top();
                //removing the station from the priority queue
                fuels.pop();
                ans = ans+1;
                continue;
            }
        }
        x++;
    }
    l = l - stations[n-1].first;
    if(p>=l){
        return ans;
    }
    while(p<l){
        if(fuels.empty()){
            return -1;
        }
        p+=fuels.top();
        fuels.pop();
        ans++;
    }
    return ans;
}

int main() {
	// Chopstics problem
	int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	pair<int, int> stations[10000];
    	for(int i=0; i<n; i++){
    	    cin>>stations[i].first>>stations[i].second;
    	}
    	int l, p;
    	cin>>l>>p;
    	cout<<min_stations(stations, n, l, p)<<endl;
    }
	return 0;
}
