class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c= grid[0].size();
        int fresh=0;
        int rotten=0;
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    rotten++;
                    q.push({i,j});
                }
            }
        }
        if(fresh==0){
            return 0;
        }        
        int ans=0;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(q.size()>0){
            int rottedThisMinute=false;
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> Node=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int x=Node.first+dx[j];
                    int y=Node.second+dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y]=2;
                        fresh--;
                        rottedThisMinute=true;
                    }
                }
            }
            if (rottedThisMinute) {
                ans++;
            }
        }
    
        if (fresh > 0) {
            return -1;
        }

        return ans;
    }
};