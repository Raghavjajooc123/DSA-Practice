#include <iostream>
using namespace std;
int cell_metosis(int n, int x, int y, int z){
    int dp[1000];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        if(i%2 == 0){
            dp[i] = min(dp[i-1]+y , dp[i/2]+x);
        }
        else{
            dp[i] = min(dp[(i+1)/2]+x+z , dp[i-1]+y);
        }
    }
    return dp[n];
}
int main() {
	// Cell Metosis
	int n;
	cin>>n;
	int x,y,z;//costs of 2n, n+1, n-1 respectively
	cin>>x>>y>>z;
	cout<<cell_metosis(n,x,y,z)<<endl;
	return 0;
}
