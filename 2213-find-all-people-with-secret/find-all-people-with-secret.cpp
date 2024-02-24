class Solution {
public:
    int visited[100001];
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        vector<pair<int, int>> adj[n];
        for (auto meeting : meetings) {
            adj[meeting[0]].push_back({meeting[1], meeting[2]});
            adj[meeting[1]].push_back({meeting[0], meeting[2]});
        }
        adj[0].push_back({firstPerson, 0});
        priority_queue<pair<int, int>> pq;
        int distance[n];

        for (int i = 0; i < n; i++) {
            distance[i] = 1e9;
        }
        memset(visited, 0, sizeof(visited));
        pq.push({0, 0});
        while (!pq.empty()) {
            int curr = pq.top().second;
            int time = -pq.top().first;
            pq.pop();
            if (visited[curr])
                continue;
            visited[curr] = true;
            for (auto x : adj[curr]) {
                int u = x.first;
                int t = x.second;
                if (t < time)
                    continue;
                pq.push({-t, u});
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                ans.push_back(i);
        }
        return ans;
    }
};