class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                if(st.find(nums[j])==st.end()){
                    st.insert(nums[j]);
                    cnt++;
                }
                ans=ans+(cnt*cnt);
            }
        }
        return ans; 
    }
};