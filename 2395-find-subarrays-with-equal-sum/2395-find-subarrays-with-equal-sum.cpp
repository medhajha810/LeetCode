class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> seenSums;
        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (seenSums.count(sum)) {
                return true;
            }
            seenSums.insert(sum);
        }
        return false;
    }
};
