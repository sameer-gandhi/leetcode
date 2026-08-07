class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pre;
        int presum=0;
        int cnt=0;
        pre[0]=1;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int need=presum-k;
            cnt+=pre[need];
            pre[presum]+=1;
        }
        return cnt;
    }
};