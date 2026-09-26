class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        int n=s.length();
        int cnt=0;
        string key="";
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt=1;
            }
            else if(s[i]==')'){
                cnt=0;
                if(mp.find(key)!=mp.end()){
                    ans+=mp[key];
                }
                else{
                    ans+="?";
                }
                key="";
            }
            else if(cnt==1){
                key+=s[i];
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};