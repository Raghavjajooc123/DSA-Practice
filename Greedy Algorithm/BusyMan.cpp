#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool endTimeCompare(pair<int, int> t1, pair<int, int> t2){
    return t1.second<t2.second;
}

int max_activities(vector<pair<int, int>> times, int n){
    sort(times.begin(), times.end(), endTimeCompare);
    int currtime = times[0].first;
    int activities = 0;
    for(int i=0; i<n; i++){
        int start_time = times[i].first;
        int end_time = times[i].second;
        if(currtime<=start_time){
            activities++;
            currtime = end_time;
        }
    }
    return activities;
}

int main() {
	// Busy man
	int t,n,s,e;
	cin>>t;
	while(t--){
	    cin>>n;
	    
	    vector<pair<int, int>> times;
	    
	    for(int i=0; i<n; i++){
	        cin>>s>>e;
	        times.push_back(make_pair(s,e));
	    }
	    
	    cout<<max_activities(times, n)<<endl;
	}
	return 0;
}
