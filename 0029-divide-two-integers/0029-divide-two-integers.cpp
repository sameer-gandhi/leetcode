class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool sign=false;
        if(dividend>=0 && divisor>0){
            sign=true;
        }
        else if(dividend<=0 && divisor<0){
            sign=true;
        }
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        long long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans=ans+(1LL<<cnt);
            n=n-(d<<cnt);
        }
        if(ans==(1LL<<31) && sign==true){
            return INT_MAX;
        }
        if(ans==(1LL<<31) && sign==false){
            return INT_MIN;
        }
        if(sign==true){
            return ans;
        }
        return -ans;
    } 
};