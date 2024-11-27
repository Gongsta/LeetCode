class Solution {
public:

    vector<int> adj[501];
    bool visited[501];
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for (int i=0;i<n;i++) {
            adj[i].clear();
        }
        for (int i=0;i<n;i++) {
            adj[i].push_back(i+1);
        }
        vector<int> ans;
        for (auto &query: queries) {
            adj[query[0]].push_back(query[1]);
            int curr = 0;
            int l = 0;
            queue<pair<int, int>> q;
            q.push({0, 0});
            memset(visited, 0, sizeof(visited));
            while (!q.empty()) {
                auto x = q.front();q.pop();
                if (x.first == n-1) {
                    l = x.second;
                    break;
                }
                for (auto v: adj[x.first]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push({v, x.second + 1});
                    }
                }
            }
            ans.push_back(l);
        }
        return ans;
    }
};