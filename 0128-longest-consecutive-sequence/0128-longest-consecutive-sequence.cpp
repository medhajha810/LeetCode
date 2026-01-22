class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        int longest=1;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                count++;
                longest=max(longest,count);
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                count=1;
            }
        }
        return longest;
        
    }
};