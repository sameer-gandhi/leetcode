class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int i=0;i<n;i++){
            int k=0;
            int j=n-1;
            while(k<=j){
                if(image[i][k]==0){
                    image[i][k]=1;
                }
                else if(image[i][k]==1){
                    image[i][k]=0;
                }
                if(k!=j){
                    if(image[i][j]==0){
                        image[i][j]=1;
                    }
                    else if(image[i][j]==1){
                        image[i][j]=0;
                    }
                }
                swap(image[i][k],image[i][j]);
                k++;
                j--;
            }
        }
        return image;
    }
};