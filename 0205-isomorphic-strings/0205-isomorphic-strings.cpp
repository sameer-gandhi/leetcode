class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mps[128]={0};
        char mpt[128]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mps[s[i]]!=mpt[t[i]]){
                return false;
            }
            mps[s[i]]=i+1;
            mpt[t[i]]=i+1;
        }
        return true;
    }
};