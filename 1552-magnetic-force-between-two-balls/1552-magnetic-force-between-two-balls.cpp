class Solution {
    bool possible(vector<int> &position ,int mxforce,int m){
        int cntballs=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=mxforce){
                cntballs++;
                last=position[i];
            }
        }
        return (cntballs>=m);
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        long long mx=position[n-1];
        long long mn=position[0];
        long long low=0;
        long long high=mx-mn;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(position,mid,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};