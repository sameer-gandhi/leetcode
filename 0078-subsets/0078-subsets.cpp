class Solution {
    void generate(int idx,vector<int> &nums,int n,vector<int> &temp,vector<vector<int>> &ans){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        generate(idx+1,nums,n,temp,ans);
        temp.pop_back();
        generate(idx+1,nums,n,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        generate(0,nums,n,temp,ans);
        return ans;
    }
};