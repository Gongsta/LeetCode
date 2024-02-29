class Solution {
public:

    int n;
    int m;
    bool visited1[501][501];
    bool visited2[501][501];
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    void dfs1(vector<vector<int>>& grid, vector<vector<int>>& islands, int row, int col, int counter) {
        if (visited1[row][col]) return;
        visited1[row][col] = true;
        islands[row][col] = counter;
        for (auto& dir: directions) {
            int nr = row + dir[0];
            int nc = col + dir[1];
            if (nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 1) {
                dfs1(grid,islands, nr, nc, counter);
            }
        }
    }

    bool dfs2(vector<vector<int>>& grid, vector<vector<int>>& islands, int row, int col, int island) {
        if (visited2[row][col]) return true;
        visited2[row][col] = true;
        bool works = islands[row][col] == island;
        for (auto& dir: directions) {
            int nr = row + dir[0];
            int nc = col + dir[1];
            if (nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 1) {
                works =  dfs2(grid,islands, nr, nc, island) && works;
            }
        }
        return works;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        for (int i=0;i<n;i++) {
           for (int j=0;j<m;j++) {
               visited1[i][j] = false;
               visited2[i][j] = false;
           }
        }
        vector<vector<int>> islands = grid1;
        // Run DFS on grid1 and set the island values
        int counter = 1;
        for (int i=0;i<n;i++) {
           for (int j=0;j<m;j++) {
               if (visited1[i][j] || grid1[i][j] == 0) continue;
               dfs1(grid1, islands, i, j, counter);
               counter++;
            }
        }

        // Run DFS on grid2 and check the island values
        int ans = 0;
        for (int i=0;i<n;i++) {
           for (int j=0;j<m;j++) {
               if (visited2[i][j] || grid2[i][j] == 0) continue;
                   cout << i << " " << j << endl;
               bool works = dfs2(grid2, islands, i, j, islands[i][j]);
               if (works && islands[i][j] != 0) {
                   ans++;
               }
            }
        }
        return ans;
    }
};