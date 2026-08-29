class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.empty()){
        //     return 0;
        // }
        // int mxlen=INT_MIN;
        // for(int i=0;i<s.length();i++){
        //     unordered_map<char,int> mp;
        //     int len=0;
        //     for(int j=i;j<s.length();j++){
        //         bool check=false;
        //         len++;
        //         mp[s[j]]++;
        //         for(auto el:mp){
        //             if(el.second>1){
        //                 check=true;
        //                 break;
        //             }
        //         }
        //         if(!check){
        //             mxlen=max(len,mxlen);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return mxlen;
        if(s.empty()){
            return 0;
        }
        int i=0;
        int j=0;
        int mxlen=0;
        int len=0;
        unordered_map<char,int> mp;
        while(i<=j && j<s.length()){
            len++;
            mp[s[j]]++;
            bool check=false;
            for(auto el:mp){
                if(el.second>1){
                    len--;
                    mp[s[i]]--;
                    i++;
                    check=true;
                    break;
                }
            }
            if(!check){
                mxlen=max(len,mxlen);
            }
            j++;
        }
        return mxlen;
    }
};