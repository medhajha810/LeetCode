class Solution {
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    void func(string s, int start, vector<vector<string>>& res, vector<string>&temp){
        if (start == s.size()) {
            res.push_back(temp);
            return;
        }
        for(int i=start;i<s.size();i++){
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                func(s, i + 1, res, temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        func(s,0,res,temp);
        return res;
        
    }
};