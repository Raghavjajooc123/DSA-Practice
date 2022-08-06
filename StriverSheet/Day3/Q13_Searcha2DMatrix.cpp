class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // brute force - O(NM)
        // int posx = -1;
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(matrix[i][j] == target){
        //             posx = i;
        //             break;
        //         }
        //     }
        // }
        // if(posx>=0){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        
        //optimized - O(N+M)
        // int Row = -1;
        // for(int i=0; i<m; i++){
        //     if(target>=matrix[i][0] && target<= matrix[i][n-1]){
        //         Row = i;
        //         break;
        //     }
        // }
        // if(Row == -1){
        //     return false;
        // }
        // else{
        //     for(int i=0; i<n; i++){
        //         if(matrix[Row][i] == target){
        //             return true;
        //         }
        //     }
        //     return false;
        // }
        
        //By taking the top right element and moving
        // int i=0, j = n-1;
        // while(i<m && j>=0){
        //     if(matrix[i][j] > target){
        //         j--;
        //     }
        //     else if(matrix[i][j] == target){
        //         return true;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return false;
        
        //doing binary search by using imaginary index
        int s = 0;
        int e = n*m -1;
        int ans = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(matrix[mid/n][mid%n] < target){
                s = mid+1;
            }
            else if(matrix[mid/n][mid%n] == target){
                return true;
            }
            else{
                e = mid-1;
            }
        }
        return false;
    }
};
