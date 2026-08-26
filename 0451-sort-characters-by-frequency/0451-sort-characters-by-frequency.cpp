class Solution {
    static bool comp(pair<char,int> p1,pair<char,int> p2){
        if(p1.second>p2.second){
            return true;
        }
        if(p1.second<p2.second){
            return false;
        }
        return p1.first<p2.first;
    }
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> temp(mp.begin(),mp.end());
        sort(temp.begin(),temp.end(),comp);
        string result="";
        for(auto [ch,freq]:temp){
            result+=string(freq,ch);
        }
        return result;
    }
};