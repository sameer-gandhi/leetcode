class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        long long ans=0;
        for(int i=0;i<n;i++){
            int temp=26-(s[i]-'a');
            ans=ans+1LL*temp*(i+1);
        }
        return ans;
    }
};