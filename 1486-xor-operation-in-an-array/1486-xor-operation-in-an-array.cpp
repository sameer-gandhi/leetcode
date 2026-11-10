class Solution {
public:
    int xorOperation(int n, int start) {
        int exor=0;
        for(int i=0;i<n;i++){
            exor=exor^(start+(2*i));
        }
        return exor;
    }
};