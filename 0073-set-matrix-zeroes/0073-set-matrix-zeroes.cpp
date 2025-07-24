class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> ans(r,vector<int>(c));
        ans=matrix;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<r;k++){
                        ans[k][j]=0;
                    }
                    for(int k=0;k<c;k++){
                        ans[i][k]=0;
                    }
                }
            }
        }
        matrix=ans;
    }
};