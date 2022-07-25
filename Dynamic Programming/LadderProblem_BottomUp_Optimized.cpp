#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int TotalWays_optimized(int n, int k){
    int dp[100] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = 0;
        int count = 0;
        for(int j = i-1; j > i-k-1 && j>=0; j--){
            dp[i]+=dp[j];
            count++;
        }
        if(count == k){
            break;
        }
    }
    for(int i=k+1; i<=n; i++){
        dp[i] = 2 * dp[i-1] - dp[i-k-1]; 
    }
    return dp[n];
}
int main() {
	// ladder problem
	int n, k;
	cin>>n>>k;
	cout<<TotalWays_optimized(n, k)<<endl;
	return 0;
}
