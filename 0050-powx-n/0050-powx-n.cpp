class Solution {
public:
    double func(double x, int e, double ans){
        if(e==0){
            return ans;
        }
        if(e%2==0){
            return func(x*x,e/2,ans);
        }
        else{
            return func(x*x, e/2,ans*x);
        }
    }
    double myPow(double x, int n) {
        if(n==0){
            return 1.0;
        }
        long int e=n;
        if(e<0){
            e=-e;
        }
        double ans=func(x,e,1.0);
        if(n>0){
            return ans;
        }
        else{
            return 1.0/ans;
        }
        
        
    }
};