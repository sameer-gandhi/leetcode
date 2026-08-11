class Solution {
    bool possible(vector<int> &nums,int mxsum,int k){
        int cntsarr=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mxsum){
                sum+=nums[i];
            }
            else{
                cntsarr++;
                sum=nums[i];
            }
        }
        return (cntsarr<=k);
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            return -1;
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long mx=*max_element(nums.begin(),nums.end());
        long long low=mx;
        long long high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,mid,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};