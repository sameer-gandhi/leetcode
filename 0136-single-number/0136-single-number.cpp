class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int exor=nums[0];
       for(int i=1;i<nums.size();i++){
        exor^=nums[i];
       }
       return exor;
    }
};