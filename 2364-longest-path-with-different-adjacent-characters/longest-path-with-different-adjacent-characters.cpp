class Solution {
public:
    int longestPath(vector<int>& parent, string& s) {
        vector<vector<int>> adj(parent.size());
        for (int i = 1;i<parent.size();i++) adj[parent[i]].push_back(i);

        int ans = 0;

        function<int(int)> longestPathInner = [&](int curr) -> int {
            pair<int, int> top_two_includes = {0, 0};
            for (int neigh: adj[curr]) {
                int include_neigh = longestPathInner(neigh);
                if (s[neigh] != s[curr]) {
                    if (include_neigh > top_two_includes.second) {
                        top_two_includes.first = top_two_includes.second;
                        top_two_includes.second = include_neigh;
                    } else if (include_neigh > top_two_includes.first) {
                        top_two_includes.first = include_neigh;
                    }
                } 
            }
            ans = max(ans, top_two_includes.first + top_two_includes.second + 1);
            return top_two_includes.second + 1;
        };

        longestPathInner(0);
        return ans;
        
    }
};