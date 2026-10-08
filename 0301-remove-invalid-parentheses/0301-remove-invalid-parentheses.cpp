class Solution {
    void solve(string s,int left,int right,vector<char> para,vector<string> &ans){
        int n=s.length();
        int cnt=0;
        for(int i=right;i<n;i++){
            if(s[i]==para[0]){
                cnt++;
            }
            else if(s[i]==para[1]){
                cnt--;
            }
            if(cnt<0){
                right=i;
                break;
            }
        }
        if(cnt<0){
            for(int i=left;i<=right;i++){
                if(s[i]!=para[1] || (i>0 && s[i-1]==s[i])){
                    continue;
                }
                s.erase(i,1);
                solve(s,i,right,para,ans);
                s.insert(s.begin()+i,para[1]);
            }
        }
        else if(cnt>0){
            reverse(s.begin(),s.end());
            solve(s,0,0,{')','('},ans);
        }
        else{
            if(para[0]=='('){
                ans.push_back(s);
            }
            else{
                reverse(s.begin(),s.end());
                ans.push_back(s);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        solve(s,0,0,{'(',')'},ans);
        return ans;
    }
};