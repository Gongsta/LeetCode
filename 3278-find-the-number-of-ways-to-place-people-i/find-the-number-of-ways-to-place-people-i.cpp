class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans =0;
        map<int, vector<int>> m;
        for (int i = 0;i<points.size();i++) {
            m[points[i][0]].push_back(points[i][1]);
        }
        vector<pair<int, int>> fixed_points;
        for (auto& x: m) {
            sort(x.second.begin(),x.second.end());
            reverse(x.second.begin(), x.second.end());
        }
        for (auto& x: m) {
            for (auto &v: x.second) {
                fixed_points.push_back({x.first, v});
            }
        }

        for (int i =0;i<points.size();i++) {
            for (int j = i + 1;j<points.size();j++) {
                if (fixed_points[i].second >= fixed_points[j].second) {
                    bool works = true;
                    for (int k = 0;k<points.size();k++) {
                        if (k == i || k == j) continue;
                        if (fixed_points[i].first <= fixed_points[k].first && fixed_points[k].first <= fixed_points[j].first && 
                        fixed_points[i].second >= fixed_points[k].second && fixed_points[k].second >= fixed_points[j].second) {
                            works = false;
                            break;
                        }
                    }
                    if (works) ans++;
                }

            }
        }
        return ans;
    }
};