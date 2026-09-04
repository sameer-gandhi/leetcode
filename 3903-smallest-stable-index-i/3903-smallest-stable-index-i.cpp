class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> stable(n);
        for(int i=0;i<n;i++){
            int mx=*max_element(nums.begin(),nums.begin()+i+1);
            int mn=*min_element(nums.begin()+i,nums.end());
            stable[i]=mx-mn;
        }
        for(int i=0;i<n;i++){
            if(stable[i]<=k){
                return i;
            }
        }
        return -1;
    }
};