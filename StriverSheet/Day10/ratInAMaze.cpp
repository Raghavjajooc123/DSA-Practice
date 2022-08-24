void solutionMaze(vector<vector<int> > &maze, int i, int j, int n, vector<vector<int> > &ans, vector<vector<int> > &curr){
    if(i<0 || i>=n || j<0 || j>=n || maze[i][j] == 0 || curr[i][j] == 1){
        return;
    }
    if(i==n-1 && j==n-1){
        curr[i][j] = 1;
        vector<int> sol;
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                sol.push_back(curr[x][y]);
            }
        }
        ans.push_back(sol);
        curr[i][j] = 0;
        return;
    }
    curr[i][j] = 1;
    solutionMaze(maze, i, j+1, n, ans, curr);
    solutionMaze(maze, i+1, j, n, ans, curr);
    solutionMaze(maze, i, j-1, n, ans, curr);
    solutionMaze(maze, i-1, j, n, ans, curr);
    curr[i][j] = 0;
    return;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int> > ans;
    vector<vector<int> > curr( n , vector<int> (n, 0));
    solutionMaze(maze, 0, 0, n, ans, curr);
    return ans;
}
