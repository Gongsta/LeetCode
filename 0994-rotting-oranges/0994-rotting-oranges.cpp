class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> distance = grid;
        int n = grid.size();
        int m = grid[0].size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                distance[i][j] = 500;
            }
        }
        vector<vector<int>> directions = {
            {1,0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == 2) {
                    map<pair<int, int>, bool> visited;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    distance[i][j] = 0;
                    while (!q.empty()) {
                        pair<int, int> p = q.front(); q.pop();
                        if (visited.count({p.first, p.second})) continue;
                        visited[{p.first, p.second}] = true;
                        for (auto dir: directions) {
                            if (p.first + dir[0] >= 0 && p.first + dir[0] < n && p.second + dir[1] >= 0 && p.second + dir[1] < m && grid[p.first + dir[0]][p.second + dir[1]] == 1) {
                                distance[p.first + dir[0]][p.second + dir[1]] = min(distance[p.first][p.second] + 1, distance[p.first + dir[0]][p.second + dir[1]]);
                                q.push({p.first + dir[0], p.second + dir[1]});
                            }
                            
                        }
                    }
                    
                }
            }
        }
                                                                                               
        int min_time = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == 1) {
                    if (distance[i][j] == 500) return -1;
                    min_time = max(min_time, distance[i][j]);
                }
            }
        }
        return min_time;
        
        
    }
};