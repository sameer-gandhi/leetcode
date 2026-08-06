class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st(nums.begin(),nums.end());
       int cnt=0;
       int mx=0;
       for(auto el:st){
        if(st.find(el-1)==st.end()){
            cnt=1;
            int x=el;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt++;
            }
            mx=max(mx,cnt);
        }
       }
    return mx;
    }
};