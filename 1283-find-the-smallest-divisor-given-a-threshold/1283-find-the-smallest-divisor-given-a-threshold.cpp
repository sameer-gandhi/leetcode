class Solution {
    long long find(vector<int> &nums,int d){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(1LL*nums[i]+d-1)/d;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx=*max_element(nums.begin(),nums.end());
        int low=1;
        int high=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long div=find(nums,mid);
            if(div<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return low;
    }
};