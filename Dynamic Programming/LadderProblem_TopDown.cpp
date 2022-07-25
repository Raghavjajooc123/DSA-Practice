#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int TotalWays(int n, int k, int * ways){
    if(n == 0){
        return 1;
    }
    if(ways[n]!=0){
        return ways[n];
    }
    int currWays = 0;
    for(int i=1; i<=k && i<=n; i++){
        ways[n-i] = TotalWays(n-i, k, ways);
        currWays += ways[n-i];
    }
    ways[n] = currWays;
    return ways[n];
}
int main() {
	// ladder problem
	int n, k;
	cin>>n>>k;
	int ways[1000] = {0};
	cout<<TotalWays(n, k, ways)<<endl;
	return 0;
}
