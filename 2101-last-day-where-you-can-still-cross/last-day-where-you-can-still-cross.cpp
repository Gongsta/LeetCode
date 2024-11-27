class Solution {
public:
    vector<vector<int>> directions = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1},
    };

    bool in_bounds(int i, int j, int row, int col) {
        return i>=0 && i < row && j >= 0 && j < col;
    }

    bool possible(int row, int col, vector<vector<int>>& cells, int day) {
        // Quick
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        vector<vector<bool>> visited = grid;
        for (int i=0;i<day;i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = true;
        }
        // Do a bfs to see if you can reach the end;
        queue<pair<int, int>> q;
        for (int j = 0;j<col;j++) {
            if (!grid[0][j]) {
                q.push({0, j});
                visited[0][j] = true;
            }
        }
        bool works = false;
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            if (x.first == row - 1) {
                works = true;
                break;
            }
            for (auto& dir: directions) {
                int new_x = x.first + dir[0];
                int new_y = x.second + dir[1];
                if (in_bounds(new_x, new_y, row, col) && !visited[new_x][new_y] && !grid[new_x][new_y]) {
                    visited[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
        }

        return works;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0;
        int r = cells.size() - 1;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (possible(row, col, cells, mid)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};