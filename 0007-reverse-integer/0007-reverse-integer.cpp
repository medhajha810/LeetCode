class Solution {
public:
    int reverse(int x) {
        int rem =0;
        int n=x;
        int rev=0;
        while(n!=0){
            rem=n%10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8)) return 0;

            rev=(rev*10)+rem;
            n=n/10;
        }
        return rev;
        
    }
};