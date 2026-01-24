class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> check;
        int maxLen = 0;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            check[s[i]]++;
            count++;

            while (check[s[i]] > 1) {
                check[s[start]]--;
                start++;
                count--;
            }

            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};