class Solution {
    void merge(vector<int> &nums,int low,int mid,int high){
        int left=low;
        int right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }

    void MergeSort(vector<int> &nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        MergeSort(nums,low,mid);
        MergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1){
            return nums;
        }
        MergeSort(nums,0,n-1);
        return nums;
    }
};