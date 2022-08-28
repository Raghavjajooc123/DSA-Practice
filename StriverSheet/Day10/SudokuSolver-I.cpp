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
    bool solver(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int k=1; k<=9; k++){
                        if(isPossible(k, i, j, board)){
                            board[i][j] = '0' + k;
                            if(solver(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
        return;
    }
};
