class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                inDegree[adj[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0;i<adj[temp].size();i++){
                inDegree[adj[temp][i]]--;
                 if(inDegree[adj[temp][i]] == 0) {
                    q.push(adj[temp][i]);  // ✅ push to queue when in-degree becomes 0
                }
            }
        }
        if(ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};
        

        
