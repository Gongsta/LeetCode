class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];  // sort by end time
             });

        int removed = 0;
        int lastEnd = INT_MIN;

        for (const auto& interval : intervals) {
            int start = interval[0];
            int end   = interval[1];

            if (start < lastEnd) {
                // overlaps with previous kept interval → remove this one
                ++removed;
            } else {
                // no overlap → keep it and update lastEnd
                lastEnd = end;
            }
        }

        return removed;
    }
};
