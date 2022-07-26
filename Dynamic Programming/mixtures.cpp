#include <iostream>
#include <climits>
using namespace std;
long long dp[1000][1000];
long long sum(int * colors, int i, int j){
    long long sum = 0;
    for(int k=i; k<=j; k++){
        sum = (sum+(colors[k]))%100;
    }
    return sum%100;
}
long long mixtures(int * colors, int i, int j){
    // base case
    if(i==j){
        return 0;
    }
    
    //looking for answer
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    //rec case
    dp[i][j] = INT_MAX;
    for(int k=i; k<=j; k++){
        dp[i][j] = min(dp[i][j], mixtures(colors,i,k)+mixtures(colors,k+1,j)+(sum(colors,i,k)*sum(colors, k+1, j)));
    }
    return dp[i][j];
}

int main() {
	// Mixtures
	int n;
	cin>>n;
	int colors[100];
	for(int i=0; i<n; i++){
	    cin>>colors[i];
	}
	//initialize DP with -1
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = -1;
        }
    }
	cout<<mixtures(colors, 0, n-1)<<endl;
	return 0;
}
