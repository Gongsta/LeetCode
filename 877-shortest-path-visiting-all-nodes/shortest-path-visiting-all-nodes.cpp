class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all_visited_bitmask = (1 << n) - 1;
        int ans = INT_MAX;

        for (int start = 0;start < n; start++) {
            vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
            queue<tuple<int, int, int>> q;
            q.push({start, (1 << start), 0});

            // Run BFS
            while (!q.empty()) {
                auto [node, bitmask, dist] = q.front(); q.pop();
                if (bitmask == all_visited_bitmask) {
                    ans = min(ans, dist);
                    break;
                }

                for (int neigh: graph[node]) {
                    int new_bitmask = bitmask | (1 << neigh);
                    if (visited[neigh][new_bitmask]) continue;
                    visited[neigh][new_bitmask] = true;
                    q.push({neigh, new_bitmask, dist + 1});
                }
            }

        }
        return ans;
        
    }
};