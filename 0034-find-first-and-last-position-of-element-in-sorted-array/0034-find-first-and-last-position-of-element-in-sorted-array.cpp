class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=n;
        int last=n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                first=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        low=0;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                last=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(first==n || nums[first]!=target){
            return {-1,-1};
        }
        return {first,last-1};
    }
};