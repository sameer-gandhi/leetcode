class Solution {
    bool find(vector<int> &nums,int d,int threshold){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(1LL*nums[i]+d-1)/d;
        }
        return (sum<=threshold);
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx=*max_element(nums.begin(),nums.end());
        int low=1;
        int high=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(find(nums,mid,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};