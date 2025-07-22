class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>SumCount;
        int length= nums.size()/2;
        SumCount[0]=-1;
        int sum=0, count=0;

        for (int i=0;i<nums.size();i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (SumCount.find(sum ) != SumCount.end()){
                count= max(count, i - SumCount[sum]);
            }
            else {
                SumCount[sum] = i;
            }
        }
        
        return count;
        
    }
};