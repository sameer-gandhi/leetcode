class Solution {
    void generate(int open,int close,string &temp,vector<string> &ans){
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }
        if(open>0){
            temp.push_back('(');
            generate(open-1,close,temp,ans);
            temp.pop_back();
        }
        if(close>0){
            if(open<close){
                temp.push_back(')');
                generate(open,close-1,temp,ans);
                temp.pop_back();
            }
        }
    }
   
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generate(n,n,temp,ans);
        return ans;
    }
};