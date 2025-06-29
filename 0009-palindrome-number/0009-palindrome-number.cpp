class Solution {
public:
    bool isPalindrome(int x) {
        int rem=0;
        long long rev=0;
        int n=x;
        if(n<0){
            return false;
        }
        while(n!=0){
            rem=n%10;
            rev=(rev*10)+rem;
            n=n/10;
        }
        if(rev==x){
            return true;
        }
        else{return false;}
    }
};