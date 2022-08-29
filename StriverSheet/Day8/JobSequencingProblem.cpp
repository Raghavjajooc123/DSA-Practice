#include <algorithm>
bool compare(vector<int> j1, vector<int> j2){
    return j1[1]>j2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare);
    int maxTime = jobs[0][0];
    for(int i=1; i<jobs.size(); i++){
        maxTime = max(maxTime, jobs[i][0]);
    }
    
    vector<int> time(maxTime+1, -1);
    time[0] = 0;
    int ans = 0;
    for(int i=0; i<jobs.size(); i++){
        for(int j=jobs[i][0]; j>0; j--){
            if(time[j] == -1){
                time[j] = jobs[i][0];
                ans+=jobs[i][1];
                break;
            }
        }
    }
    return ans;
}
