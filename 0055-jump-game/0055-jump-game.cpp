class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*int maxReach = 0;  // The furthest index we can reach so far

        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) return false;  // If we can't reach this point
            maxReach = max(maxReach, i + nums[i]);
        }*/

        int n=nums.size();
        int reached=0;

        for(int i=n-1;i>=0;i--){
            if(nums[i]+i>=reached){
                reached=i;
            }
        }
        if(reached==0){
            return true;
        }
        else{return false;}

        
    }
};
