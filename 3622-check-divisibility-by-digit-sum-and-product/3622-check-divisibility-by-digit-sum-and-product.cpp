class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int digitsum=0;
        int digitproduct=1;
        while(temp>0){
            int ld=temp%10;
            digitsum+=ld;
            digitproduct*=ld;
            temp/=10;
        }
        int total=digitsum+digitproduct;
        if(n%total==0){
            return true;
        }
        return false;
    }
};