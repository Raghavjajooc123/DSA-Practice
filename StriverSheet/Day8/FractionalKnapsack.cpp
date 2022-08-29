#include <algorithm>
bool compare(pair<int, int> p1, pair<int, int> p2){
    double r1 = (double)p1.second/(double)p1.first;
    double r2 = (double)p2.second/(double)p2.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), compare);
    double ans = 0.0;
    int curr_wt = 0;
    for(int i=0; i<n; i++){
        if(curr_wt + items[i].first <= w){
            ans += items[i].second;
            curr_wt += items[i].first;
        }
        else{
            double r = (double)items[i].second/items[i].first;
            ans += (r*(w-curr_wt));
            curr_wt = w;
            break;
        }
    }
    return ans;
}
