class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n= prices.size();
        stack<int> s;
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()>prices[i]){
                s.pop();
            }
            if(!s.empty()){
                res[i]=prices[i]-s.top();
            }
            else{
                res[i]=prices[i];
            }
            s.push(prices[i]);
        }
        return res;
        
    }
};