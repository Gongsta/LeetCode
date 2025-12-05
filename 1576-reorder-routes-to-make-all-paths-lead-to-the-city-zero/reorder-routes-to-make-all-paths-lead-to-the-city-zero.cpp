class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for (auto& connection: connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        int ans = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto [neigh, cost]: adj[x]) {
                if (visited[neigh]) continue;
                ans += cost;
                visited[neigh] = true;
                q.push(neigh);
            }
        }
        return ans;
    }
};