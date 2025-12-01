class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int digit){
        for(int i=0;i<9;i++){
            if(board[row][i]==digit){
                return false;
            }
            if(board[i][col]==digit){
                return false;
            }
        }
        int srow=(row/3)*3;
        int scol=(col/3)*3;
        for(int i=srow;i<srow+3;i++){
            for(int j=scol;j<scol+3;j++){
                if(board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>& board, int row, int col){
        if(row==9){
            return true;
        }
        int nextrow=row;
        int nextcol=col+1;
        if(nextcol==9){
             nextrow=row+1;
             nextcol=0;
        }
        if(board[row][col]!='.'){
            return solve(board,nextrow,nextcol);
        }

        for(char digit='1';digit<='9';digit++){
            if(isSafe(board,row,col,digit)){
                board[row][col]=digit;
                if(solve(board,nextrow,nextcol)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};