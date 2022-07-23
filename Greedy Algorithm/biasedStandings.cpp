#include <iostream>
#include <algorithm>
using namespace std;

bool rankCompare(pair<string, int> p1, pair<string, int> p2){
    return p1.second<p2.second;
}

int leaderboard(pair<string, int> ranks[100], int n){
    int badness = 0;
    sort(ranks, ranks+n, rankCompare);
    for(int i=0; i<n; i++){
        int diff = abs(ranks[i].second - i - 1);
        badness += diff;
    }
    return badness;
}
int leaderboard_optimized(pair<string, int> ranks[100], int n){
    int badness = 0;
    int counts[101] = {0};
    for(int i=0; i<n; i++){
        counts[ranks[i].second]++;
    }
    int j = 1;
    for(int i=1; i<=n; i++){
        while(counts[i]>0){
            badness+=abs(i-j);
            counts[i]--;
            j++;
        }
    }
    return badness;
}

int main() {
    // Biased Standings
    int n;
    cin>>n;
    
    pair<string, int> ranks[100];
    for(int i=0; i<n; i++){
        cin>>ranks[i].first>>ranks[i].second;
    }
    
    cout<<leaderboard(ranks, n)<<endl;
    cout<<leaderboard_optimized(ranks, n)<<endl;
    
    return 0;
}
