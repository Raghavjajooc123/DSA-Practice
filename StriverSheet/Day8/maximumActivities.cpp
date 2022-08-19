#include<algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> times;
    int n = start.size();
    for(int i=0; i<n; i++){
        times.push_back(make_pair(finish[i], start[i]));
    }
    sort(times.begin(), times.end());
    int currtime = times[0].first;
    int count = 1;
    for(int i=1; i<n; i++){
        if(currtime<=times[i].second){
            count++;
            currtime = times[i].first;
        }
    }
    return count;
}
