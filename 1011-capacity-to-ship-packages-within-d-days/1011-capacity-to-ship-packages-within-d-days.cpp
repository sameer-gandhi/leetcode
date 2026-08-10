class Solution {
    int find(vector<int> &weights,int capacity){
        long long load=0;
        int days=1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
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
            int reqday=find(weights,mid);
            if(reqday<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};