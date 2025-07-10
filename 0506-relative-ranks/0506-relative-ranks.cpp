class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> index(n); // stores original indices
        
        // Initialize index array
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        // Sort the index array based on score values
        sort(index.begin(), index.end(), [&](int a, int b) {
            return score[a] > score[b]; // Descending order
        });

        vector<string> result(n);

        // Assign ranks based on sorted index
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                result[index[i]] = "Gold Medal";
            } else if (i == 1) {
                result[index[i]] = "Silver Medal";
            } else if (i == 2) {
                result[index[i]] = "Bronze Medal";
            } else {
                result[index[i]] = to_string(i + 1);
            }
        }

        return result;
        
    }
};