class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans;
        string temp;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                if(cnt>1){
                    ans.push_back(s[i]);
                }
            }
            else{
                cnt--;
                if(cnt>=1){
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};