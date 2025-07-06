class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // The furthest index we can reach so far

        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) return false;  // If we can't reach this point
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};
