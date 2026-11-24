class Solution {
    int help(vector<int> &nums,int goal){
        int n=nums.size();
        if(goal<0){
            return 0;
        }
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                if(nums[l]==1){
                    sum--;
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt= help(nums,goal) - help(nums,goal-1);
        return cnt;
    }
};