#include <iostream>
#include <climits>
using namespace std;

int friends(int * dp, int n){
    // base case
    if(n==1 || n==0){
        return 1;
    }
    //looking for answer
    if(dp[n] != 0){
        return dp[n];
    }
    //rec case
    dp[n] = friends(dp, n-1) + (n-1)*friends(dp, n-2);
    return dp[n];
}

int friends_BU(int n){
    int dp[1000];
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n];
}

int main() {
	// friends problem
	int n;
	cin>>n;
	int dp[1000] = {0};
	cout<<friends(dp, n)<<endl;
	cout<<friends_BU(n)<<endl;
	return 0;
}
