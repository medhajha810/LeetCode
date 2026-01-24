class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        vector<int> need(128, 0);
        for(char c : t) need[c]++;

        int required = t.size(); 
        int i = 0, j = 0;

        int minLen = INT_MAX;
        int startIndex = 0;

        while(j < s.size()){
            if(need[s[j]] > 0) required--;
            need[s[j]]--;
            j++;

            while(required == 0){
                if(j - i < minLen){
                    minLen = j - i;
                    startIndex = i;
                }

                need[s[i]]++;
                if(need[s[i]] > 0) required++;
                i++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIndex, minLen);
    }
};