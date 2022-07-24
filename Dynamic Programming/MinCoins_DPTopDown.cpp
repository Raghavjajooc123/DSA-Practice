#include <iostream>
#include <climits>
using namespace std;
int min_coins(int n, int currencySize, int* coins, int * minCoinsStorage){
    //base case
    if(n == 0){
        return 0;
    }
    //Stored value
    if(minCoinsStorage[n] != 0){
        return minCoinsStorage[n];
    }
    //rec case
    int minimumCoins = INT_MAX;
    for(int i=0; i<currencySize && coins[i]<=n; i++){
        int op = min_coins(n - coins[i], currencySize, coins, minCoinsStorage);
        minimumCoins = min(minimumCoins, op);
    }
    minCoinsStorage[n] = minimumCoins + 1;
    return minCoinsStorage[n];
}

int main() {
	// minimum steps to one
	int n; 
	cin>>n;
	int coins[] = {1, 7, 10};
	int currencySize = 3;
	int minCoinsStorage[1000] = {0};
	for(int i=0; i<currencySize; i++){
	    minCoinsStorage[coins[i]] = 1;
	}
	cout<<min_coins(n, currencySize, coins, minCoinsStorage)<<endl;
	return 0;
}
