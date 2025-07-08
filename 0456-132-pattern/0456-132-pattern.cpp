class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;
        int third = INT_MIN;  // this represents nums[k]

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;  // found nums[i] < nums[k] < nums[j]
            }

            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};
