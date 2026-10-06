class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        int ans=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ans++;
                st.push('(');
            }
            else{
                if(st.empty()!=true && st.top()=='('){
                    ans--;
                    st.pop();
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
};