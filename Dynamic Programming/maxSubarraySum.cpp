#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int maxSubArraySum_kadanes(int * arr, int n){
    int MaxSum = 0;
    int currSum = 0;
    for(int i=0; i<n; i++){
        currSum += arr[i];
        if(currSum < 0){
            currSum = 0;
        }
        if(currSum>MaxSum){
            MaxSum = currSum;
        }
    }
    return MaxSum;
}
int maxSubArraySum_Brute(int * arr, int n){
    int maxSum = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int currSum = 0;
            for(int k=i; k<j; k++){
                currSum += arr[k];
            }
            if(currSum > maxSum){
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}
int maxSubArraySum_Optimized(int * arr, int n){
    int maxSum = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        arr[i] = sum;
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int currSum = arr[j] - arr[i];
            if(currSum>maxSum){
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}
int maxSubArraySum_DP(int * arr, int n){
    int dp[100];
    dp[0] = arr[0]>0?arr[0]:0;
    int max_so_far = dp[0];
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1]+arr[i];
        if(dp[i]<0){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}
int main() {
	// wines problem
	int n;
	cin>>n;
	int arr[100];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	cout<<maxSubArraySum_DP(arr, n);
	return 0;
}
