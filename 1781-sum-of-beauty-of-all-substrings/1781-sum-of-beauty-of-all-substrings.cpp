class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> mp;
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                int mn=INT_MAX;
                int mx=INT_MIN;
                for(auto el:mp){
                    if(el.second>mx){
                        mx=el.second;
                    }
                    if(el.second<mn){
                        mn=el.second;
                    }
                }
                sum+=mx-mn;
            }
        }
        return sum;
    }
};