class Solution {
    bool possible(vector<int> &candies,long long mx,long long k){
        long long cnts=0;
        for(int i=0;i<candies.size();i++){
            cnts+=1LL*candies[i]/mx;
        }
        return (cnts>=k);
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total=0;
        for(int i=0;i<candies.size();i++){
            total+=candies[i];
        }
        long long low=1;
        long long high=total/k;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(possible(candies,mid,k)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};