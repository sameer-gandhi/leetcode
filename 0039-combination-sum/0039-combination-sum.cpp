class Solution {
    void generatecombinations(int idx,vector<int> &nums,int n,int target,vector<int> &temp,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=n){
            return;
        }
        if(nums[idx]<=target){   
            temp.push_back(nums[idx]);
            generatecombinations(idx,nums,n,target-nums[idx],temp,ans);
            temp.pop_back();
        }
        generatecombinations(idx+1,nums,n,target,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;
        generatecombinations(0,candidates,n,target,temp,ans);
        return ans;
    }
};