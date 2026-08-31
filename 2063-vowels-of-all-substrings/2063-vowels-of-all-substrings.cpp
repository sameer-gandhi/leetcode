class Solution {
public:
    long long countVowels(string word) {
        int n=word.length();
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                cnt+=1LL*(i+1)*(n-i);
            }
        }
        return cnt;
    }
};