class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for(int row=0;row<9;row++){
            for(int j=0;j<9;j++){
                if(board[row][j]!='.'){
                    if(s.find(board[row][j])!=s.end()){
                        return false;
                    }
                    else s.insert(board[row][j]);
                }
                
            }
            s.clear();
        }
        for(int col=0;col<9;col++){
            for(int i=0;i<9;i++){
                if(board[i][col]!='.'){
                    if(s.find(board[i][col])!=s.end()){
                        return false;
                    }
                    else s.insert(board[i][col]);
                }
                
            }
            s.clear();
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                for(int row=i;row<i+3;row++){
                    for(int col=j;col<j+3;col++){
                        if(board[row][col]!='.'){
                            if(s.find(board[row][col])!=s.end()){
                                return false;
                            }
                            else s.insert(board[row][col]);
                        }
                        
                    }
                }
                s.clear();
            }
        }
        return true;

    }
};