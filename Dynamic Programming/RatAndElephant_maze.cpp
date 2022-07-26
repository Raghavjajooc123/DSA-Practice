#include <iostream>
using namespace std;
int rat_ways(int m, int n){
    //doing by bottom up DP approach
    int dp[100][100] = {0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}
int elephant_ways(int m, int n){
    //doing by bottom up DP approach
    int dp[100][100] = {0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
            }
            else if(i==0){
                for(int k=0; k<j; k++){
                    dp[i][j]+=dp[i][k];
                }
            }
            else if(j==0){
                for(int k=0; k<i; k++){
                    dp[i][j]+=dp[k][j];
                }
            }
            else{
                for(int k=0; k<i; k++){
                    dp[i][j]+=dp[k][j];
                }
                for(int k=0; k<j; k++){
                    dp[i][j]+=dp[i][k];
                }
            }
        }
    }
    //printing the dp 
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m-1][n-1];
}
int main() {
	// rat and elephant in a maze - no of ways
	int m,n;
	cin>>m>>n;
	cout<<rat_ways(m,n)<<endl;
	cout<<elephant_ways(m,n)<<endl;
	return 0;
}
