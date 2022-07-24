#include <iostream>
#include <climits>
using namespace std;
int min_coins_BU(int n, int currencySize, int* coins){
    int dp[1000];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int minimumcoins = INT_MAX;
        for(int j=0; j<currencySize && coins[j]<=i; j++){
            int option = dp[i-coins[j]];
            minimumcoins = min(minimumcoins, option);
        }
        dp[i] = minimumcoins + 1;
    }
    return dp[n];
}

int main() {
	// minimum steps to one
	int n; 
	cin>>n;
	int coins[] = {1, 7, 10};
	int currencySize = 3;
	cout<<min_coins_BU(n, currencySize, coins)<<endl;
	return 0;
}
