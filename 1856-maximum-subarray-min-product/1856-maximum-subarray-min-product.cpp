class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // Step 1: Prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Monotonic stack to find Previous Smaller and Next Smaller
        vector<int> left(n, -1), right(n, n);
        stack<int> s;

        // Previous Smaller (strictly less)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }

        // Clear and reuse stack
        while (!s.empty()) s.pop();

        // Next Smaller (strictly less)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            if (!s.empty()) right[i] = s.top();
            s.push(i);
        }

        // Step 3: Compute max min-product
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long total = prefix[right[i]] - prefix[left[i] + 1];
            res = max(res, total * nums[i]);
        }

        return res % MOD;
    }
};
