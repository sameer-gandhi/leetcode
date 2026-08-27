class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        int end=-1;
        for(int i=0;i<=s.length();i++){
            if(i==s.length() || s[i]==' '){
            end=i-1;
            while(start<end){
                swap(s[start++],s[end--]);
            }
            start=i+1;
            }
        }
        return s;
    }
};