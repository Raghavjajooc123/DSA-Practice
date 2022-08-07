class Solution {
public:
    int dp[100][100] = {0};
    int pathHelper(int x, int y){
        //base case
        if(x==0 || y==0){
            return dp[x][y] = 1;
        }
        if(dp[x][y]!=0){
            return dp[x][y];
        }
        return dp[x][y] = pathHelper(x-1, y) + pathHelper(x, y-1);
    }
    int uniquePaths(int m, int n) {
        
        //top down DP approach
        return pathHelper(m-1, n-1);
        
        // bottom-Up DP approach
        // int dp[100][100] = {0};
        // for(int i=0; i<m; i++){
        //     dp[i][0] = 1;
        // }
        // for(int j = 0; j<n; j++){
        //     dp[0][j] = 1;
        // }
        // for(int i=1; i<m; i++){
        //     for(int j=1; j<n; j++){
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];
    }
};
