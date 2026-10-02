class Solution {
    void generate(int idx,int n,string &temp,vector<string> &ans){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        if(temp.empty() || temp.back()=='0' || temp.back()=='1'){
            temp.push_back('1');
            generate(idx+1,n,temp,ans);
            temp.pop_back();
        }
        if(temp.empty() || temp.back()!='0'){
            temp.push_back('0');
            generate(idx+1,n,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp;
        generate(0,n,temp,ans);
        return ans;
    }
};