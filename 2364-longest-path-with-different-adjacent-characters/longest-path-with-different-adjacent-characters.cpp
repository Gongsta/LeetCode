class Solution {
public:
    int longestPath(vector<int>& parent, string& s) {
        vector<vector<int>> adj(parent.size());
        for (int i = 1;i<parent.size();i++) adj[parent[i]].push_back(i);

        int ans = 0;

        function<tuple<int,int, int>(int)> longestPathInner = [&](int curr) -> tuple<int,int,int> {
            pair<int, int> top_two_includes = {0, 0};
            int exclude = 0;
            for (int neigh: adj[curr]) {
                auto [include_neigh, exclude_neigh, include_both_neigh] = longestPathInner(neigh);
                if (s[neigh] != s[curr]) {
                    if (include_neigh > top_two_includes.second) {
                        top_two_includes.first = top_two_includes.second;
                        top_two_includes.second = include_neigh;
                    } else if (include_neigh > top_two_includes.first) {
                        top_two_includes.first = include_neigh;
                    }
                } else {
                    exclude = max(exclude, exclude_neigh);
                    exclude = max(exclude, include_both_neigh);
                }
            }
            ans = max(ans, top_two_includes.first + top_two_includes.second + 1);
            return {top_two_includes.second + 1, exclude, top_two_includes.first + top_two_includes.second + 1};
        };

        longestPathInner(0);
        return ans;
        
    }
};