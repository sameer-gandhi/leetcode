class Solution {

    bool checkforeven(vector<int> &nums1,int i,int el){
        for(int j=0;j<nums1.size();j++){
            if(j!=i && (el-nums1[j])%2==0){
                return true;
            }
        }
        return false;
    }
    bool evencheck(vector<int> &nums1){
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0 || checkforeven(nums1,i,nums1[i])){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool checkforodd(vector<int> &nums1,int i,int el){
        for(int j=0;j<nums1.size();j++){
            if(j!=i && (el-nums1[j])%2!=0){
                return true;
            }
        }
        return false;
    }

    bool oddcheck(vector<int> &nums1){
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0 || checkforodd(nums1,i,nums1[i])){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool uniformArray(vector<int>& nums1) {
        return evencheck(nums1) || oddcheck(nums1);
    }
};