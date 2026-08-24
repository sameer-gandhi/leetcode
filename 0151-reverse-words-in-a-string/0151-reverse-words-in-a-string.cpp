class Solution {
public:
    string reverseWords(string str) {
        int n=str.length();
        int low=0;
        string s="";
        for(int i=0;i<n;i++){
            if(str[i]==' '){
                if(s.empty() || s.back()==' '){
                    continue;
                }
            }
            s+=str[i];
        }
        if(!s.empty() && s.back()==' '){
            s.pop_back();
        }
        int k=s.length();
        for(int i=0;i<=k;i++){
            if(i==k || s[i]==' '){
                int high=i-1;
                while(low<high){
                    swap(s[low++],s[high--]);
                }
                low=i+1;
            }
        }
        int left=0;
        int right=k-1;
        while(left<right){
            swap(s[left++],s[right--]);
        }
        return s;
    }
};