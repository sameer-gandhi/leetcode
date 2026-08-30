class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mni=min_element(nums.begin(),nums.end())-nums.begin();
        int mxi=max_element(nums.begin(),nums.end())-nums.begin();
        int front=max(mni,mxi)+1;
        int back=n-min(mni,mxi);
        int bothsides=min(mni,mxi)+1+n-max(mni,mxi);
        return min({front,back,bothsides});
    }
};