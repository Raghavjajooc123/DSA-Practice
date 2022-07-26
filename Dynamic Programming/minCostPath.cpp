#include <iostream>
#include <climits>
using namespace std;
int min_cost(int cost[][100], int r, int c){
    int dp[100][100];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i==0 && j==0){
                dp[i][j] = cost[i][j];
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1] + cost[i][j];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j] + cost[i][j];
            }
            else{
                dp[i][j] = min(dp[i][j-1], dp[i-1][j])+cost[i][j];
            }
        }
    }
    return dp[r-1][c-1];
}

int main() {
	// min cost from 0,0 to r,c problem
	int r,c;
	cin>>r>>c;
	int cost[100][100];
	for(int i=0; i<r; i++){
	    for(int j=0; j<c; j++){
	        cin>>cost[i][j];
	    }
	}
	cout<<min_cost(cost,r,c)<<endl;
	return 0;
}
