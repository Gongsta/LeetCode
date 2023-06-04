class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        
        vector<vector<int>> directions = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1},
            {-1,-1},
            {1,-1},
            {1,1},
            {-1,1},
        };
        queue<pair<int, int>> q;
        int n = grid.size();
        int dist[n][n];
        memset(dist, -1, sizeof(dist));
        q.push({0,0});
        dist[0][0] = 1;
        
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            if (p.first == n-1 && p.second == n-1) {
                return dist[p.first][p.second];
            }
            for (auto& dir: directions) {
                int i = p.first + dir[0];
                int j = p.second + dir[1];
                if (i>=0 && j >=0 && i < n && j < n && grid[i][j] == 0 && dist[i][j] == -1) {
                    dist[i][j] = dist[p.first][p.second] + 1;
                    q.push({i,j});
                }
            }
        }
        return -1;
        
    }
};