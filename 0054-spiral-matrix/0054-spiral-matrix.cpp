class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int top=0;
        int left=0;
        int right=matrix[0].size()-1;
        int bottom=matrix.size()-1;

        while(left<=right && top<=bottom){
            for(int col=left;col<=right;col++){
                v.push_back(matrix[top][col]);
            }
            top++;
            for(int row=top;row<=bottom;row++){
                v.push_back(matrix[row][right]);
            }
            right--;
            if(top<=bottom){
                for(int col=right;col>=left;col--){
                    v.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            if(left<=right){
                for(int row=bottom;row>=top;row--){
                    v.push_back(matrix[row][left]);
                }
                left++;
            }
        }
      return v;  
    }
};