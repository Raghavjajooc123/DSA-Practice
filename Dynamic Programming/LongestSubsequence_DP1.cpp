#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int LongestSubsequence_DP1(int * arr, int n){
    int dp[100] = {1};
    for(int i=0; i<n; i++){
        int maxlen = 0;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                maxlen = max(maxlen, dp[j]);
            }
        }
        dp[i] = maxlen + 1;
    }
    //printing the array
    for(int i=0; i<n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    int maxlen = 0;
    for(int i=0; i<n; i++){
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}
int main() {
	// Longest Subsequences DP-1 problem
	int n;
	cin>>n;
	int arr[100];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	cout<<LongestSubsequence_DP1(arr, n)<<endl;
	return 0;
}
