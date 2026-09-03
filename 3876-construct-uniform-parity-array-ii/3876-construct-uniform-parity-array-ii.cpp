class Solution {
    // bool checkforeven(vector<int> &nums,int i,int el){
    //     for(int j=0;j<nums.size();j++){
    //         if(i!=j && (el-nums[j]>=1 && (el-nums[j])%2==0)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // bool checkeven(vector<int> &nums){
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]%2==0 || checkforeven(nums,i,nums[i])){
    //             continue;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // bool checkforodd(vector<int> &nums,int i,int el){
    //     for(int j=0;j<nums.size();j++){
    //         if(i!=j && (el-nums[j]>=1 && (el-nums[j])%2!=0)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // bool checkodd(vector<int> &nums){
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]%2!=0 || checkforodd(nums,i,nums[i])){
    //             continue;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
public:
    bool uniformArray(vector<int>& nums1) {
        //return checkeven(nums1) || checkodd(nums1);
        bool hasodd=false;
        int mn=nums1[0];
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                hasodd=true;
            }
            if(nums1[i]<mn){
                mn=nums1[i];
            }
        }
        if(mn%2!=0){
            return true;
        }
        return !hasodd;
    }
};