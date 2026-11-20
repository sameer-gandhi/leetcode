class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int left=0;
        int right=0;
        int mxlen=0;
        int mxfreq=0;
        vector<int> freq(26,0);
        while(right<n){
            freq[s[right]-'A']++;
            mxfreq=max(mxfreq,freq[s[right]-'A']);
            if((right-left+1)-mxfreq>k){
                freq[s[left]-'A']--;
                left++;
            }
            mxlen=max(mxlen,right-left+1);
            right++;
        }
        return mxlen;
    }
};