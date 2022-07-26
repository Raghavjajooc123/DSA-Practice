#include <iostream>
#include <climits>
using namespace std;
int noOfPaths(int grid[][100], int r, int c){
    if(grid[0][0]){
        return 0;
    }
    int dp[100][100];
    dp[0][0] = 1;
    for(int i=0; i<r; i++){
        if(grid[i][0] == 1){
            for(int k=i; k<r; k++){
                dp[k][0] = 0;
            }
            break;
        }
        else{
            dp[i][0] = 1;
        }
    }
    for(int j=0; j<c; j++){
        if(grid[0][j] == 1){
            for(int k=j; k<c; k++){
                dp[0][k] = 0;
            }
            break;
        }
        else{
            dp[0][j] = 1;
        }
    }
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(grid[i][j] == 1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }
    //printing the dp table
//     for(int i=0; i<r; i++){
// 	    for(int j=0; j<c; j++){
// 	        cout<<dp[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
    return dp[r-1][c-1];
}

int main() {
	// no of ways in a grid
	int r,c;
	cin>>r>>c;
	int grid[100][100];
	for(int i=0; i<r; i++){
	    for(int j=0; j<c; j++){
	        grid[i][j] = 0;
	    }
	}
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
	    int a,b;
	    cin>>a>>b;
	    grid[a-1][b-1] = 1;
	}
	cout<<noOfPaths(grid,r,c)<<endl;
	return 0;
}
