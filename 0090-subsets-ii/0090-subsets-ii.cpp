class Solution {
    void subsets(int idx,vector<int> &nums,int n,vector<int> &temp,vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i=idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            subsets(i+1,nums,n,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        subsets(0,nums,n,temp,ans);
        return ans;   
    }
};