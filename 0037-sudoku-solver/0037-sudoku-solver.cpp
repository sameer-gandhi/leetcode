class Solution {
    bool possible(vector<vector<char>>& board,char choice,int row,int col){
        for(int i=0;i<9;i++){
            if(board[row][i]==choice || board[i][col]==choice || board[3*(row/3)+i/3][3*(col/3)+i%3]==choice){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char choice='1';choice<='9';choice++){
                        if(possible(board,choice,i,j)){
                            board[i][j]=choice;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};