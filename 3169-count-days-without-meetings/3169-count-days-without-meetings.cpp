class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    int freeDays = 0, last = 0;
    for (auto& m : meetings) {
        int st = m[0], ed = m[1];
        if (st > last + 1) freeDays += st - last - 1;
        last = max(last, ed);
    }
    freeDays += days - last;
    return freeDays;
}

};