class Solution {
    bool possible(vector<int> &weights,int capacity,int days){
        long long load=0;
        int cntdays=1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                cntdays++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return (cntdays<=days);
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=*max_element(weights.begin(),weights.end());
        long long sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        long long low=mx;
        long long high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(weights,mid,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};