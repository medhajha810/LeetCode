class Solution {
public:
    int fun(int i, vector<int>& nums, vector<int>& dp){
        if (dp[i] != -1) return dp[i];
        int l=1;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i]){
                int ans = 1+fun(j,nums,dp);
                l=max(ans,l);
            }
        }
        return dp[i] = l;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,fun(i,nums,dp));
        }
        return ans;
        
    }
};