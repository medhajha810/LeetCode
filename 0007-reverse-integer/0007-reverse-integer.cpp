class Solution {
public:
    int reverse(int x) {
        int rem =0;
        int n=x;
        int rev=0;
        while(n!=0){
            rem=n%10;
            rev=(rev*10)+rem;
            n=n/10;
        }
        return rev;
        
    }
};