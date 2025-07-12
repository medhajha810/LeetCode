
bool compareMeetings(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort the meetings by their start time
        sort(meetings.begin(), meetings.end(), compareMeetings);

        int freeDays = 0;           // To count how many days are free
        int lastDayWithMeeting = 0; // The last day which has a meeting

        // Go through each meeting
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            // If there is a gap between the last meeting and the current
            // one
            if (start > lastDayWithMeeting + 1) {
                freeDays += (start - lastDayWithMeeting - 1);
            }

            // Update the last meeting day
            if (end > lastDayWithMeeting) {
                lastDayWithMeeting = end;
            }
        }

        // Add the remaining free days after the last meeting
        if (lastDayWithMeeting < days) {
            freeDays += (days - lastDayWithMeeting);
        }

        return freeDays;
    }
};