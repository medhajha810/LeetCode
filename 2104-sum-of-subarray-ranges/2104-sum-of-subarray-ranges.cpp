class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        // Max Contribution
        stack<int> s;
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || nums[s.top()] < nums[i])) {
                int mid = s.top(); s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;
                long long count = (mid - left) * (right - mid);
                result += (long long)nums[mid] * count;
            }
            s.push(i);
        }

        // Min Contribution
        while (!s.empty()) s.pop(); 

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || nums[s.top()] > nums[i])) {
                int mid = s.top(); s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;
                long long count = (mid - left) * (right - mid);
                result -= (long long)nums[mid] * count;
            }
            s.push(i);
        }

        return result;
    }
};
