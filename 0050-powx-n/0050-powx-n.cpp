class Solution {
    double find(double x,long long nn){
        if(nn==0){
            return 1;
        }
        if(nn==1){
            return x;
        }
        double half=find(x,nn/2);
        if(nn%2==0){
            return half*half; 
        }
        return x*half*half;
    }
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        long long nn=n;
        if(n<0){
            nn=-(long long)n;
        }
        double ans=find(x,nn);
        // while(nn>0){
        //     if(nn%2){
        //         ans=ans*x;
        //         nn--;
        //     }
        //     else{
        //         x=x*x;
        //         nn/=2;
        //     }
        // }
        if(n<0){
            return (double)1.0/(double)ans;
        }
        return ans;
    }
};