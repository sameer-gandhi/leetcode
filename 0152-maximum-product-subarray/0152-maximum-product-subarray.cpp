class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long prep=1;
        long long sufp=1;
        long long mxproduct=nums[0];
        for(int i=0;i<n;i++){
            if(prep==0){
                prep=1;
            }
            if(sufp==0){
                sufp=1;
            }
            prep*=nums[i];
            sufp*=nums[n-1-i];
            mxproduct=max(mxproduct,max(prep,sufp));
        }
        return mxproduct;
    }
};