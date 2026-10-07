class Solution {
    bool palindrome(string &s,int left,int right){
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
    void generate(int idx,string s,int n,vector<string> &temp,vector<vector<string>> &ans){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(palindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                generate(i+1,s,n,temp,ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> temp;
        generate(0,s,n,temp,ans);
        return ans;
    }
};