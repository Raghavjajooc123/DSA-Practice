#include <algorithm>
bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first!=b.first ? a.first<b.first : a.second.second<b.second.second;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<pair<int, pair<int, int>>> times;
    for(int i=0; i<n; i++){
        times.push_back(make_pair(end[i], make_pair(start[i], i+1)));
    }
    sort(times.begin(), times.end(), compare);
    vector<int> ans;
    int currtime = times[0].first;
    ans.push_back(times[0].second.second);
    for(int i=1; i<n; i++){
        if(currtime < times[i].second.first){
            ans.push_back(times[i].second.second);
            currtime = times[i].first;
        }
    }
    return ans;
}
