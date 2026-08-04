class Solution {
public:

bool check(int x,int *temp){
    if(x>=0 && x<=9){
        int last=*temp%10;
        *temp/=10;
        return last==x;
    }
    bool result=check(x/10,temp) and x%10 == (*temp)%10;
    *temp/=10;
    return result;
}
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }
        int temp=x;
    bool result=check(x,&temp);
        if(result){
            return 1;
        }
        else{
            return 0;
        }
    }
};