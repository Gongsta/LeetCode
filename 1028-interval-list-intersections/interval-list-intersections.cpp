class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        /*
        - Perfect overlap
        - One is a sub-interval of the other

        Compare two intervals, check for intersection,  and move the smaller one forward.
        Terminate when one of the intervals reach the end
        */
        int i = 0;
        int j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;
        while (i < n && j < m) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            // compute intervals
            int intersection_start = max(start1, start2);
            int intersection_end = min(end1, end2);
            if (intersection_start <= intersection_end) {
                ans.push_back({intersection_start, intersection_end});
            }
            if (end1 < end2) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
        
    }
};