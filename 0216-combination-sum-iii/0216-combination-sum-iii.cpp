class Solution {
    void combinations(int idx,vector<int> &nums,int mxlen,int target,vector<int> &temp,vector<vector<int>> &ans){
        if(target==0 && mxlen==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            combinations(i+1,nums,mxlen-1,target-nums[i],temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;
        combinations(0,nums,k,n,temp,ans);
        return ans;
    }
};