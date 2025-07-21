class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                inDegree[adj[i][j]]++;
            }
        }
        int ans=0;
        queue<int> q;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int temp=q.front();
            q.pop();
            ans++;
            for(int i=0;i<adj[temp].size();i++){
                inDegree[adj[temp][i]]--;
                 if(inDegree[adj[temp][i]] == 0) {
                    q.push(adj[temp][i]);  // ✅ push to queue when in-degree becomes 0
                }
            }
        }
        return ans==numCourses;
    }
};
        
