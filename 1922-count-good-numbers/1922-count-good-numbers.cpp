class Solution {
public:
    long long power(long long x,long long y){
        long long mod=1000000007;
        if(y==0){
            return 1;
        }
        if(y==1){
            return x;
        }
        long long half=power(x,y/2);
        if(y%2==0){
            return (half*half)%mod;
        }
        else{
            return (x*half*half)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long mod=1000000007;
        long long evenways=n/2+n%2;
        long long oddways=n/2;
        return (power(5,evenways)*power(4,oddways))%mod;
    }
};