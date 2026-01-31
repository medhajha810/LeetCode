class Solution {
public:
    void getAll(string op, string ip, vector<string> &result) {
        if (ip.length() == 0) {
            result.push_back(op);
            return;
        }

        char ch = ip[0];
        ip.erase(ip.begin());

        // If digit: only 1 option
        if (ch >= '0' && ch <= '9') {
            op.push_back(ch);
            getAll(op, ip, result);
        }
        else {
            // Option 1: lowercase
            string op1 = op;
            op1.push_back(tolower(ch));

            // Option 2: uppercase
            string op2 = op;
            op2.push_back(toupper(ch));

            getAll(op1, ip, result);
            getAll(op2, ip, result);
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string op = "";
        string ip = S;

        getAll(op, ip, result);
        return result;
    }
};
