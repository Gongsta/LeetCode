class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> suffix(n);
        suffix[n - 1] = events[n - 1][2];
        for (int i = n - 2;i>=0;i--) {
            suffix[i] = max(events[i][2], suffix[i + 1]);
        }
        int ans = events[0][2];
        vector<int> v = {INT_MAX, INT_MAX, INT_MAX};
        for (int i = 0;i<n;i++) {
            ans = max(ans, events[i][2]);
            // binary search start greater than the current end
            v[0] = events[i][1];
            auto it = upper_bound(events.begin(), events.end(), v);
            if (it != events.end()) {
                int idx = it - events.begin();
                ans = max(ans, events[i][2] + suffix[idx]);
            }
        }
        return ans;
        
    }
};