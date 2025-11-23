class Solution {
public:
    int GCD(int m, int n){
        if(n==0){
            return m;
        }
        return GCD(n, m%n);
    }
    int findGCD(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int b=*min_element(nums.begin(),nums.end());
        return GCD(a,b);
        
    }
};