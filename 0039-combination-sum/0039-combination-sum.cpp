class Solution {
public:
    void backtrack(int idx, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(temp);  // Found a valid combination
            return;
        }
        if (target < 0 || idx >= candidates.size()) {
            return;  // No valid combination
        }

        // Include current candidate (can reuse)
        temp.push_back(candidates[idx]);
        backtrack(idx, candidates, target - candidates[idx], temp, result);
        temp.pop_back();  // Backtrack

        // Exclude current candidate and move to next
        backtrack(idx + 1, candidates, target, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(0, candidates, target, temp, result);
        return result;
    }
};
