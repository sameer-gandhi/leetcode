class Solution {
    bool find(int idx,vector<vector<char>> &board,int m,int n,string &word,int i,int j){
        if(idx>=word.length()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='*'){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        bool temp=false;
        board[i][j]='*';
        temp= temp || find(idx+1,board,m,n,word,i+1,j) || find(idx+1,board,m,n,word,i-1,j) || find(idx+1,board,m,n,word,i,j+1) || find(idx+1,board,m,n,word,i,j-1);
        board[i][j]=word[idx];
        return temp;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        if(word.length()==1 && board[0][0]==word[0]){
            return true;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(find(0,board,m,n,word,i,j)){
                        return true;                    
                    }
                }
            }
        }
        return false;
    }
};