class Solution {
    int mxelement(vector<vector<int>> &mat,int n,int m,int col){
        int idx=-1;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(mat[i][col]>mx){
                mx=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mxelement(mat,n,m,mid);
            int left=-1;
            int right=-1;
            if(mid-1>=0){
                left=mat[row][mid-1];
            }
            if(mid+1<m){
                right=mat[row][mid+1];
            }
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};