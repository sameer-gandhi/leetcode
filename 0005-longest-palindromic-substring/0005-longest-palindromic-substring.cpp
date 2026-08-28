class Solution {
public:
    string longestPalindrome(string s) {
        string ans=string(1,s[0]);
        int mxlen=0;
        int n=s.length();
        int low=-1;
        int high=-1;
        for(int i=0;i<s.length();i++){
            low=i;
            high=i;
            while((low>=0 && high<n) && (s[low]==s[high])){
                low--;
                high++;
            }
            string palindrome=s.substr(low+1,high-low-1);
            if(palindrome.length()>ans.length()){
                ans=palindrome;
            }

            low=i;
            high=i+1;
            while((low>=0 && high<n) && (s[low]==s[high])){
                low--;
                high++;
            }
            palindrome=s.substr(low+1,high-low-1);
            if(palindrome.length()>ans.length()){
                ans=palindrome;
            }
        }
        return ans;
    }
};