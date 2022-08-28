class Solution {
public:
    bool isSafe(int i, int j, vector<vector<int>> pos, int n){
        for(int x=0; x<n; x++){
            if(pos[x][j] == 1)
                return false;
        }
        int temp1 = i;
        int temp2 = j;
        while(temp1>=0 && temp2>=0){
            if(pos[temp1][temp2] == 1)return false;
            temp1--;
            temp2--;
        }
        temp1 = i;
        temp2 = j;
        while(temp2<n && temp1>=0){
            if(pos[temp1][temp2] == 1)return false;
            temp1--;
            temp2++;
        }
        
        return true;
    }
    bool nQueens(vector<vector<string>>& ans, int n, int count, vector<vector<int>> &pos){
        //base case
        if(count == n){
            vector<string> temp;
            for(int i=0; i<n; i++){
                string curr = "";
                for(int j=0; j<n; j++){
                    if(pos[i][j] == 1)
                        curr += "Q";
                    else
                        curr += ".";
                }
                temp.push_back(curr);
            }
            ans.push_back(temp);
            return false;
        }

        for(int i=0; i<n; i++){
            if(isSafe(count, i, pos, n)){
                pos[count][i] = 1;
                if(nQueens(ans, n, count+1, pos))return true;
                pos[count][i] = 0;
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> pos(n, vector<int>(n,0));
        bool a = nQueens(ans, n, 0, pos);
        return ans;
    }
};
