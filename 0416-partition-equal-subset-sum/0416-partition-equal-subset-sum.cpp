class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n= arr.size();
        const int mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]])%mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][target];
        // code here
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        return perfectSum(nums, target) > 0;
    }
};