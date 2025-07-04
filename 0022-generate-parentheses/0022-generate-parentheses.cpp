class Solution {
    void Parenthesis(vector<string>&result, string ans, int open, int close, int n){
        if(close==n){
            result.push_back(ans);
        }
        if(open<n){
            Parenthesis(result, ans+'(', open+1,close, n);
        }
        if(open>close){
            Parenthesis(result, ans+')', open,close+1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        Parenthesis(result, "", 0, 0, n);
        return result;
        
    }
};