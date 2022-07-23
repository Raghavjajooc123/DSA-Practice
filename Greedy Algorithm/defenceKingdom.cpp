#include <iostream>
#include <algorithm>
using namespace std;
bool comparex(pair<int, int> p1, pair<int, int> p2){
    return p1.first<p2.first;
}
bool comparey(pair<int, int> p1, pair<int, int> p2){
    return p1.second<p2.second;
}
int maxRectangle(pair<int, int> arr[], int h, int w, int n){
    
    sort(arr, arr+n, comparex);
    int max_xdiff = arr[0].first-1;
    for(int i=0; i<n-1; i++){
        int xdiff = arr[i+1].first - arr[i].first - 1;
        max_xdiff = max(max_xdiff, xdiff);
    }
    max_xdiff = max(max_xdiff, abs(h - arr[n-1].first) - 1);
    // cout<<max_xdiff<<endl;
    
    sort(arr, arr+n, comparey);
    int max_ydiff = arr[0].second-1;
    for(int i=0; i<n-1; i++){
        int ydiff = arr[i+1].second - arr[i].second - 1;
        max_ydiff = max(max_ydiff, ydiff);
    }
    max_ydiff = max(max_ydiff, abs(w - arr[n-1].second) - 1);
    // cout<<max_ydiff<<endl;
    
    return max_xdiff*max_ydiff;
}

int main() {
    // Defence of a kingdom
    int t;
    cin>>t;
    while(t--){
        int h, w, n;
        cin>>h>>w>>n;
        pair<int, int> arr[100];
        for(int i=0; i<n; i++){
            cin>>arr[i].first>>arr[i].second;
        }
        cout<<maxRectangle(arr, h, w, n)<<endl;
    }
    
    return 0;
}
