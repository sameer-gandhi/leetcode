class Solution {
    int help(vector<int> &nums,int k){
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return help(nums,k) - help(nums,k-1);
    }
};