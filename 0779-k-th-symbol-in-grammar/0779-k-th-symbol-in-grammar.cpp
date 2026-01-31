class Solution {
public:
    int kthGrammar(int n, int k) {
        long long mid = (1LL << (n - 1)) / 2;
        if(n==1 && k==1){
            return 0;
        }
        if(k<=mid){
            return kthGrammar(n-1,k);
        }
        else{
            return !(kthGrammar(n-1,k-mid));
        }
        
    }
};