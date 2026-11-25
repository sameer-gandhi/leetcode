class Solution {
    int help(vector<int> &nums,int k){
        if(k<0){
            return 0;
        }
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        int odd=0;
        while(r<n){
            odd=odd+(nums[r]%2);
            while(odd>k){
                odd=odd-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt= help(nums,k) - help(nums,k-1);
        return cnt;
    }
};