class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        /*
        1. Sort by start (keep track of indices)
        2. For each interval, binary search the end value (for the first start >= end)
        */
        for (int i = 0;i<intervals.size();i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> ans(intervals.size(), -1);
        for (int i = 0;i<intervals.size();i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int idx = intervals[i][2];

            vector<int> target = {end, INT_MIN, INT_MIN};
            auto p = lower_bound(intervals.begin(), intervals.end(), target);
            if (p != intervals.end()) {
                ans[idx] =  (*p)[2];
            }
        }
        return ans;

        
    }
};