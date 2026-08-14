class Solution {
    bool find(vector<int> &piles,int k,int h){
        long long totalhours=0;
        for(int i=0;i<piles.size();i++){
            totalhours+=(1LL*piles[i]+k-1)/k;
        }
        return (totalhours<=h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(find(piles,mid,h)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};