class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> check;
        int maxLen = 0;
        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            check[s[j]]++;

            while (check[s[j]] > 1) {
                check[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j-i+1);
        }

        return maxLen;
    }
};