class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algorithm
        int n=nums.size();
        int sum=0;
        int mxsum=nums[0];
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mxsum){
                mxsum=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return mxsum;
    }
};