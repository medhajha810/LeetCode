class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort the meetings based on start time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int freeDays = 0;
        int last = 0;

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            if (start > last + 1) {
                freeDays += start - last - 1;
            }

            if (end > last) {
                last = end;
            }
        }

        if (last < days) {
            freeDays += days - last;
        }

        return freeDays;
    }
};