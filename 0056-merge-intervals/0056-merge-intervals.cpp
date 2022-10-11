class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> interval;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i=1;i<intervals.size();i++) {
            if (intervals[i][0] <= end) { // We need to merge
                end = max(end, intervals[i][1]);
            } else {
                interval.clear();
                interval.push_back(start);
                interval.push_back(end);
                ans.push_back(interval);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
        }
        // Add the start and end
        interval.clear();
        interval.push_back(start);
        interval.push_back(end);
        ans.push_back(interval);
        
        return ans;
        
    }
};