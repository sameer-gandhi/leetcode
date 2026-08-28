class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['M']=1000;
        mp['D']=500;
        mp['C']=100;
        mp['L']=50;
        mp['X']=10;
        mp['V']=5;
        mp['I']=1;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length() && mp[s[i]]<mp[s[i+1]]){
                ans-=mp[s[i]];
            }
            else{
                ans+=mp[s[i]];
            }
        }
        return ans;
    }
};