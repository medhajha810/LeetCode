class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        arr.push_back(newInterval);
        int n = arr.size();
        sort(arr.begin(), arr.end());
        ans.push_back(arr[0]);
        for (int i = 0; i < n; i++) {
            if (arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
        
    }
};