class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();int c=grid[0].size();
        queue<pair<int,int>> q;
        if(grid[0][0]==1 || grid[r-1][c-1]==1){
            return -1;
        }
        q.push({0,0});
        grid[0][0]=1;
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> Node = q.front();
                q.pop();
                for(int j=0;j<8;j++){
                    int x=Node.first+dx[j];
                    int y=Node.second+dy[j];
                    if(Node.first==r-1 && Node.second==c-1){
                        return ans;
                    }
                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y] ==0){
                        q.push({x,y});
                        grid[x][y] = 1 ;
                    
                    }
                }
            }
            ans++;
        }
        return -1;
        
    }
};
        
