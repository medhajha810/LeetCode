class Solution {
public:
    void generate(int idx, string& s, vector<string>& res,int prev){
        if(idx==s.size()){
            res.push_back(s);
            return;
        }
        if(prev!=0){
            s[idx]='0';
            prev=0;
            generate(idx+1,s,res,prev);
        }
        s[idx]='1';
        prev=1;
        generate(idx+1,s,res,prev);
        
    }
    vector<string> validStrings(int n) {
        vector<string>res;
        string s(n,'\0');
        int prev=1;
        generate(0,s,res,prev);
        return res;
        
    }
};