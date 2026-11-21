class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int mnlen=INT_MAX;
        int cnt=0;
        int l=0;
        int r=0;
        int sidx=-1;
        vector<int> freq(256,0);
        for(auto el:t){
            freq[el]++;
        }
        while(r<n){
            if(freq[s[r]]>0){
                cnt++;
            }
            freq[s[r]]--;
            while(cnt==t.length()){
                if(r-l+1<mnlen){
                    mnlen=r-l+1;
                    sidx=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return (sidx==-1)?(""):s.substr(sidx,mnlen);
    }
};