class Solution {
public:
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        for(i=0;i<n;i++){
            if(isPrime(nums[i])){
                break;
            }
        }
        for(j=n-1;j>=0;j--){
            if(isPrime(nums[j])){
                break;
            }
        }
        return abs(i-j);
        
    }
};