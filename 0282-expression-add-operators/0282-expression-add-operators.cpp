class Solution {
    void solve(int idx,string &num,int target,string temp,vector<string> &ans,long long pre,long long res){
        if(idx>=num.length()){
            if(res==target){
                ans.push_back(temp);
            }
            return;
        }
        long long curr=0;
        string st="";
        for(int i=idx;i<num.length();i++){
            if(i>idx && num[idx]=='0'){
                break;
            }
            st+=num[i];
            curr=curr*10+num[i]-'0';
            if(idx==0){
                solve(i+1,num,target,st,ans,curr,curr);
            }
            else{
                solve(i+1,num,target,temp+'+'+st,ans,curr,res+curr);
                solve(i+1,num,target,temp+'-'+st,ans,-curr,res-curr);
                solve(i+1,num,target,temp+'*'+st,ans,pre*curr,res-pre+(pre*curr));
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp;
        solve(0,num,target,temp,ans,0,0);
        return ans;
    }
};