class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        vector<vector<int>>directions = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1,0}
        };
        queue<vector<int>> q;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '1') { // Discovered new island that we haven't visited
                    count++;
                    q.push({i,j});
                    while (!q.empty()) {
                        vector<int> v = q.front(); q.pop();
                        if (visited[v[0]][v[1]]) continue;
                        visited[v[0]][v[1]] = true;
                        for (auto direction: directions) {
                            int new_i = direction[0] + v[0];
                            int new_j = direction[1] + v[1];
                            if (new_i >=0 && new_j >= 0 && new_i < n && new_j < m && !visited[new_i][new_j] && grid[new_i][new_j] == '1') {
                                q.push({new_i, new_j});
                            }
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        return count;
        
    }
};