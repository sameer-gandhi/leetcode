class Solution{
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        int num=0;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        if(i<s.length()){
            if(s[i]=='-'){
                sign=-1;
                i++;
            }
            else if(s[i]=='+'){
                i++;
            }
        }
        while(i<s.length() && s[i]=='0'){
            i++;
        }
        while((i<s.length()) && (s[i]>='0' && s[i]<='9')){
            int digit=s[i]-'0';
            if(num>INT_MAX/10){
                if(sign==1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
            if(num==INT_MAX/10){
                if(sign==1){
                    if(digit>=7){
                        return INT_MAX;
                    }
                }
                else{
                    if(digit>=8){
                        return INT_MIN;
                    }
                }
            }
            num=num*10+digit;
            i++;
        }
        return sign*num;
    }
 };