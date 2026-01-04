class Solution {
public:
    int row_sum(vector<vector<int>>& grid, int i, int j) {
        return grid[i][j] + grid[i][j+1] + grid[i][j+2];
    }
    int col_sum(vector<vector<int>>& grid, int i, int j) {
        return grid[i][j] + grid[i+1][j] + grid[i+2][j];
    }
    int diag_sum(vector<vector<int>>& grid, int i, int j) {
        return grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
    }
    int diag_sum_rev(vector<vector<int>>& grid, int i, int j) {
        return grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
    }

    int min_num(vector<vector<int>>& grid, int i, int j) {
        int min_n = INT_MAX;
        for (int k = 0;k<3;k++) {
            for (int l = 0;l<3;l++) {
                min_n = min(grid[i+k][j+l], min_n);
            }
        }
        return min_n;
    }

    int max_num(vector<vector<int>>& grid, int i, int j) {
        int max_n = 0;
        for (int k = 0;k<3;k++) {
            for (int l = 0;l<3;l++) {
                max_n = max(grid[i+k][j+l], max_n);
            }
        }
        return max_n;
    }
    bool is_distinct(vector<vector<int>>& grid, int i, int j) {
        unordered_set<int> s;
        for (int k = 0;k<3;k++) {
            for (int l = 0;l<3;l++) {
                s.insert(grid[i+k][j+l]);
            }
        }
        return s.size() == 9;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0;i<n-2;i++) {
            for (int j = 0;j<m-2;j++) {
                int max_n = max_num(grid, i, j);
                int min_n = min_num(grid, i, j);
                if (max_n > 9 || min_n == 0 || !is_distinct(grid, i, j)) continue;
                int target = row_sum(grid, i, j);
                if (row_sum(grid, i+1, j) == target &&
                row_sum(grid, i+2,j) == target && 
                col_sum(grid, i, j) == target &&
                col_sum(grid, i, j+1) == target &&
                col_sum(grid, i, j+2) == target &&
                diag_sum(grid, i, j) == target &&
                diag_sum_rev(grid, i, j) == target
                ) ans++;
            }
        }
        return ans;
        
        
    }
};