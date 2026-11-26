class Solution {
public:
    bool canAliceWin(int n) {
        int remove=10;
        int k=0;
        while(n>=remove){
            n-=remove;
            remove--;
            k++;
        }
        return k%2==1;
    }
};