class Solution {
public:
    void nQueens(int& ans, int n, int count, bitset<30> &col, bitset<30> &d1, bitset<30> &d2){
        if(count == n){ ans++; return; }
        for(int i=0; i<n; i++){
            if(col[i] == 0 && d1[count-i+(n-1)] == 0 && d2[count+i] == 0){
                col[i] = d1[count-i+(n-1)] = d2[count+i] = 1;
                nQueens(ans, n, count+1, col, d1, d2);
                col[i] = d1[count-i+(n-1)] = d2[count+i] = 0;
            }
        }
        return;
    }
    int totalNQueens(int n) {
        int ans = 0;
        bitset<30> col, d1, d2;
        nQueens(ans, n, 0, col, d1, d2);
        return ans;
    }
};
