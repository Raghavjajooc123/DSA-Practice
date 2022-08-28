class Solution {
public:
    bool isPossible(int k, int i, int j, vector<vector<char>> board){
        for(int x=0; x<9; x++){
            if(board[i][x] == '0'+k || board[x][j] == '0'+k)return false;
        }
        i = (i/3)*3;
        j = (j/3)*3;
        for(int x = i; x<i+3; x++){
            for(int y = j; y<j+3; y++){
                if(board[x][y] == '0'+k)return false;
            }
        }
        return true;
    }
    bool solver(vector<vector<char>>& board, int i, int j){
        if(i==9) return true;
        if(i<9 && j<9 && board[i][j] != '.'){
            if(j==8){
                return solver(board, i+1, 0);
            }
            else{
                return solver(board, i, j+1);
            }
        }
        
        if(board[i][j] == '.'){
            for(int k=1; k<=9; k++){
                if(isPossible(k, i, j, board)){
                    board[i][j] = '0' + k;
                    if(j==8){
                        bool a = solver(board, i+1, 0);
                        if(a) return true;
                    }
                    else{
                        bool a = solver(board, i, j+1);
                        if(a) return true;
                    }
                    board[i][j] = '.';
                }
            }
            return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0, 0);
        return;
    }
};
