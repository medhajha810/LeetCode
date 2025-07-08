class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        vector<int> res(n,-1);
        for(int i=n-1;i>=0;i--){
            if(!s.empty()){
                res[i]=s.top();
            }
            if (s.empty() || arr[i] > s.top()) {
                s.push(arr[i]);
            }
        }
        return res;
    }
};