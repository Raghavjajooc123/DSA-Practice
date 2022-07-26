#include <iostream>
#include <climits>
using namespace std;
int LongestSubsequence_DP2(int * arr, int n){
    int dp[100];
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n; i++){
        for(int pos = 0; pos<n; pos++){
            if(dp[pos]<arr[i] && dp[pos+1]>arr[i]){
                dp[pos+1] = arr[i];
            }
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
	// longest subsequences DP-2 problem
	int n;
	cin>>n;
	int arr[100];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	cout<<LongestSubsequence_DP2(arr, n)<<endl;
	return 0;
}
