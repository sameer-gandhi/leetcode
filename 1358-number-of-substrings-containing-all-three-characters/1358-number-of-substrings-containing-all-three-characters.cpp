class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int> freq(3,-1);
        int cnt=0;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']=i;
            if(freq[0]!=-1 && freq[1]!=-1 && freq[2]!=-1){
                int mn=min(freq[0],freq[1]);
                mn=min(freq[2],mn);
                cnt=cnt+mn+1;
            }
        }
        return cnt;
    }
};