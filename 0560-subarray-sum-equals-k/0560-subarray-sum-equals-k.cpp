class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>SumCount;
        SumCount[0]=1;
        int sum=0, count=0;

        for (int num : nums) {
            sum+=num;
            if (SumCount.count(sum-k)) {
                count+=SumCount[sum-k];
            }

            SumCount[sum]++;
        }

        return count;
    }
};
