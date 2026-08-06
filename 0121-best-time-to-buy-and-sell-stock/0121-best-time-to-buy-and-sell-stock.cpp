class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxprofit=0;
        int minbuycost=prices[0];
        for(int i=1;i<prices.size();i++){
            minbuycost=min(minbuycost,prices[i]);
            int profitorloss=prices[i]-minbuycost;
            mxprofit=max(mxprofit,profitorloss);
        }
        return mxprofit;
    }
};