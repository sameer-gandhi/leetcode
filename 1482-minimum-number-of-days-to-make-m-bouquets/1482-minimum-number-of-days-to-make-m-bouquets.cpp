class Solution {
    int make(vector<int> &bloomDay,int days,int k){
        int cnt=0;
        int noofbouquet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                cnt++;
            }
            else{
                noofbouquet+=cnt/k;
                cnt=0;
            }
        }
        noofbouquet+=cnt/k;
        return noofbouquet;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=1LL*m*k;
        if(val>n){
            return -1;
        }
        int mx=*max_element(bloomDay.begin(),bloomDay.end());
        int low=1;
        int high=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquet=make(bloomDay,mid,k);
            if(bouquet>=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};