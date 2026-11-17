class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        int zeros=0;
        int mxlen=0;
        while(right<n){
            if(nums[right]==0){
                zeros++;
            }
            if(zeros>k){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            if(zeros<=k){
                mxlen=max(mxlen,right-left+1);
            }
            right++;
        }
        return mxlen;
    }
};