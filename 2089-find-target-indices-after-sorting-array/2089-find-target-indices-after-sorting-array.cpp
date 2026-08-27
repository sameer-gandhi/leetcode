class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int last=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(first==nums.size() || nums[first]!=target){
            return {};
        }
        vector<int> ans;
        for(int i=first;i<=last-1;i++){
            ans.push_back(i);
        }
        return ans;
    }
};