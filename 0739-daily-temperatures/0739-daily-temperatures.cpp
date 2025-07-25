class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> s;
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                res[i]=s.top()-i;
            }
            s.push(i);
        }
        return res;
        
    }
};