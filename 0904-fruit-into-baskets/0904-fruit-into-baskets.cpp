class Solution {
public:
    int totalFruit(vector<int>& s) {
        int k = 2;
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        int mx = 0;

        while(j < s.size()){
            mp[s[j]]++;

            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};