class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mx=*max_element(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                k++;
            }
            else{
                break;
            }
        }
        return k;
    }
};