#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int TotalWays(int n, int k){
    int dp[100] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = 0;
        for(int j = i-1; j > i-k-1 && j>=0; j--){
            dp[i]+=dp[j];
        }
    }
    return dp[n];
}
int main() {
	// ladder problem
	int n, k;
	cin>>n>>k;
	cout<<TotalWays(n, k)<<endl;
	return 0;
}
