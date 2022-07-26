#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int LongestSubsequence_DP2_optimized(int * arr, int n){
    //since the array is strictly increasing so we can use binary search in this optimized approach
    int dp[n+1];
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n; i++){
        int idx = upper_bound(dp, dp+n+1, arr[i]) - dp;
        if(arr[i]>dp[idx-1]){
            dp[idx] = arr[i];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(dp[i]!=INT_MAX){
            ans = i;
        }
    }
    return ans;
}
int main() {
	// Longest Subsequence DP2 -- optimized problem
	int n;
	cin>>n;
	int arr[100];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	cout<<LongestSubsequence_DP2_optimized(arr, n)<<endl;
	return 0;
}
