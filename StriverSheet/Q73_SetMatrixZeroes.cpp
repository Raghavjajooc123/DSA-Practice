class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> presentx(m, 0);
        vector<int> presenty(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    presentx[i] = 1;
                    presenty[j] = 1;
                }
            }
        }
        
        for(int i=0; i<m; i++){
            if(presentx[i] == 1){
                for(int k=0; k<n; k++){
                    matrix[i][k] = 0;
                }
            }
        }
        
        for(int j=0; j<n; j++){
            if(presenty[j] == 1){
                for(int k=0; k<m; k++){
                    matrix[k][j] = 0;
                }
            }
        }
        
        return;
    }
};
