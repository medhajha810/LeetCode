class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        if(arr.empty()) return ans;
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