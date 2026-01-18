class Solution {
public:
    int row_sum(vector<vector<int>>& grid, int i, int j, int cnt) {
        int total = 0;
        for (int l =0;l<cnt;l++) {
            total += grid[i][j+l];
        }
        return total;
    }

    int col_sum(vector<vector<int>>& grid, int i, int j, int cnt) {
        int total = 0;
        for (int l =0;l<cnt;l++) {
            total += grid[i+l][j];
        }
        return total;
    }

    int diag_sum(vector<vector<int>>& grid, int i, int j, int cnt) {
        int total = 0;
        for (int l =0;l<cnt;l++) {
            total += grid[i+l][j+l];
        }
        return total;
    }

    int rev_diag_sum(vector<vector<int>>& grid, int i, int j, int cnt) {
        int total = 0;
        for (int l =0;l<cnt;l++) {
            total += grid[i+l][j+cnt - 1 -l];
        }
        return total;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i =0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                int target = 0;
                for (int k = 1;k<=min(n - i, m - j);k++) {
                    target += grid[i][j + k - 1];
                    bool works = true;
                    // Compute remaining row sums
                    for (int l = 0;l<k;l++) {
                        works = works && (row_sum(grid, i+l, j, k) == target);
                    }
                    // col sums
                    for (int l = 0;l<k;l++) {
                        works = works && (col_sum(grid, i, j + l, k) == target);
                    }
                    // diagonal sums
                    works = works && (diag_sum(grid, i, j, k) == target);
                    works = works && (rev_diag_sum(grid, i, j, k) == target);
                    if (works) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
        
    }
};