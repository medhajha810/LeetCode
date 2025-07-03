class Solution {
public:
    void func(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& result){
        result.push_back(temp);
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]);           // Include nums[i]
            func(nums, i + 1, temp, result);   // Recurse
            temp.pop_back();                   // Backtrack
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        func(nums, 0, temp, result);
        return result;
        
    }
};