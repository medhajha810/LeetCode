class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();int c=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        int ans=0;
        vector<int> dx={0,0,-1,1};
        vector<int> dy={1,-1,0,0};

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> Node = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int x=Node.first+dx[j];
                    int y=Node.second+dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && mat[x][y] ==-1){
                        q.push({x,y});
                        mat[x][y] = 1 + mat[Node.first][Node.second];
                    }
                }
            }
        }
        return mat;
        
    }
};