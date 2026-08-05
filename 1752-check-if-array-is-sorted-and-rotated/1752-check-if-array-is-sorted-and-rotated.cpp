class Solution {
    bool rotateleft(vector<int> &nums,int n){
        vector<int> temp(nums.begin(),nums.end());
        if(n<0){
            return false;
        }
        bool check=true;
        reverse(temp.begin(),temp.begin()+n);
        reverse(temp.begin()+n,temp.end());
        reverse(temp.begin(),temp.end());
        for(int i=1;i<temp.size();i++){
            if((temp[i]<temp[i-1])){
                return rotateleft(nums,n-1);
            }
        }
        return true;
    }
public:
    bool check(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        return rotateleft(nums,nums.size()-1);
    }
};