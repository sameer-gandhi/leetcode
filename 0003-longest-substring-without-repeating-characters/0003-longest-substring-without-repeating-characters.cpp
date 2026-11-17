class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int left=0;
        int right=0;
        int mxlen=0;
        vector<int> hash(256,-1);
        while(right<s.length()){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
            mxlen=max(mxlen,right-left+1);
            hash[s[right]]=right;
            right++;
        }
        return mxlen;
    }
};