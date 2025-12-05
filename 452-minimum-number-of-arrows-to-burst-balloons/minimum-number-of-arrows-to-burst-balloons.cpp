class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> points_p;
        for (auto& p: points) {
            points_p.push_back({p[1], p[0]});
        }
        sort(points_p.begin(), points_p.end());
        int l = 0;
        int r = 0;
        int n = points.size();
        int ans = 0;
        while (l < n && r < n) {
            auto [end, start] = points_p[l];
            while (r+1 < n && points_p[r+1].second <= end) r++;
            ans++;
            l = r + 1;
        }
        return ans;
        
    }
};