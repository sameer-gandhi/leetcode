class Solution {
public:
void generate(int idx,vector<int> &nums,int n,int target,vector<int> &temp,vector<vector<int>> &ans){
    if(target==0){
        ans.push_back(temp);
    }
    for(int i=idx;i<n;i++){
        if(nums[i]>target) break;
        if(i>idx && nums[i]==nums[i-1]) continue;
        temp.push_back(nums[i]);
        generate(i+1,nums,n,target-nums[i],temp,ans);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        generate(0,candidates,n,target,temp,ans);
        return ans;
    }
};