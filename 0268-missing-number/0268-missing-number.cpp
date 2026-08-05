class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int exor=n;
        for(int i=0;i<n;i++){
            exor^=nums[i];
            exor^=i;
        }
        return exor;
    }
};