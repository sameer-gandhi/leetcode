class Solution {
    
    // int countpairs(vector<int> &nums,int low,int mid,int high){
    //     int cnt=0;
    //     int left=low;
    //     int right=mid+1;
    //     for(int i=low;i<=mid;i++){
    //         while(right<=high && nums[i] > 2*1LL*nums[right]){
    //             right++;
    //         }
    //         cnt+=(right-(mid+1));
    //     }
    //     return cnt;
    // }

    int countpairs(vector<int> &nums,int low,int mid,int high){
        int cnt=0;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]>2LL*nums[right]){
                right++;
                cnt+=mid-left+1;
            }
            else{
                left++;
            }
        }
        return cnt;
    }


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
    int ms(vector<int> &nums,int low,int high){
        int cnt=0;
        if(low>=high){
            return cnt;
        }
        int mid=low+(high-low)/2;
        cnt+=ms(nums,low,mid);
        cnt+=ms(nums,mid+1,high);
        cnt+=countpairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        cnt=ms(nums,0,n-1);
        return cnt;
    }
};