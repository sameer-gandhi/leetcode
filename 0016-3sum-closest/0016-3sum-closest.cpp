class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int num=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                if(abs(target-temp)<abs(target-num)){
                    num=temp;
                }
                if(temp==target){
                    return temp;
                }
                else if(temp<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return num;
    }
};