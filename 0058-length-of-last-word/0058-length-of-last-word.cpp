class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1;
        while(s[n]==' '){
            n--;
        }
        int cnt=0;
        for(int i=n;i>=0;i--){
            if(s[i]!=' '){
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};