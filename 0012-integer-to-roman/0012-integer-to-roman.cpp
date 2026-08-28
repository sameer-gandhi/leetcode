class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> value={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans="";
        int i=0;
        for(int i=0;num>0;i++){
            if(num>=value[i]){
                int cnt=num/value[i];
                while(cnt--){
                    ans+=roman[i];
                }
                num=num%value[i];
            }
        }
        return ans;
    }
};