class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int mxarea=0;
        int left=0;
        int right=n-1;
        while(left<right){
            int currentarea=min(height[left],height[right])*(right-left);
            if(currentarea>mxarea){
                mxarea=currentarea;
            }
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return mxarea;
    }
};