class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score=0;
        for(int i=0;i<k;i++){
            score+=cardPoints[i];
        }
        int mxscore=score;
        int ridx=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            score=score-cardPoints[i]+cardPoints[ridx];
            mxscore=max(mxscore,score);
            ridx--;
        }
        return mxscore;
    }
};