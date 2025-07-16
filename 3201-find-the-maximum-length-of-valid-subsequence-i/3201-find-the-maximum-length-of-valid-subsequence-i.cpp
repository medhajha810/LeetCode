class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Case 1: Try alternating parity
        int altLen = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if ((nums[i] + prev) % 2 == 1) {
                altLen++;
                prev = nums[i];
            }
        }

        // Case 2: Try same parity
        int sameOdd = 0, sameEven = 0;
        for (int num : nums) {
            if (num % 2 == 0) sameEven++;
            else sameOdd++;
        }

        int sameLen = max(sameEven, sameOdd);

        return max(altLen, sameLen);
    }
};
