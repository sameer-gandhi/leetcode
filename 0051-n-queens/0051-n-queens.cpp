class Solution {
    void place(int col,vector<string> &chessboard,int n,vector<vector<string>> &ans,vector<int> &leftrow,vector<int> &lowerdiagonal,vector<int> &upperdiagonal){
        if(col>=n){
            ans.push_back(chessboard);
            return;
        }
        for(int row=0;row<n;row++){
            if(lowerdiagonal[row+col]==0 && upperdiagonal[(n-1)+(col-row)]==0 && leftrow[row]==0){
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[(n-1)+(col-row)]=1;
                chessboard[row][col]='Q';
                place(col+1,chessboard,n,ans,leftrow,lowerdiagonal,upperdiagonal);
                chessboard[row][col]='.';
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[(n-1)+(col-row)]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>chessboard;
        vector<vector<string>> ans;
        vector<int> leftrow(n,0);
        vector<int> lowerdiagonal(2*n-1,0);
        vector<int> upperdiagonal(2*n-1,0);
        for(int i=0;i<n;i++){
            string str(n,'.');
            chessboard.push_back(str);
        }
        place(0,chessboard,n,ans,leftrow,lowerdiagonal,upperdiagonal);
        return ans;
    }
};