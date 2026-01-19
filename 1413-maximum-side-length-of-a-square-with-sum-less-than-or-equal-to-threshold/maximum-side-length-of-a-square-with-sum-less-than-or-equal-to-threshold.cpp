class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<vector<int>> prefix_row = mat;
        vector<vector<int>> prefix_col = mat;
        for (int row = 0;row<n;row++) {
            for (int col = 0;col < m;col++) {
                if (col > 0) {
                    prefix_row[row][col] += prefix_row[row][col-1];
                }
                if (row > 0) {
                    prefix_col[row][col] += prefix_row[row-1][col];
                }
            }
        }

        for (int row = 0;row<n;row++) {
            for (int col = 0;col < m;col++) {
                for (int width = 1;width<=min(n - row, m - col);width++) {
                    int curr_sum = 0;
                    for (int r = row;r < row + width;r++) {
                            if (col == 0) {
                                curr_sum += prefix_row[r][col + width - 1];
                            } else {
                                curr_sum += prefix_row[r][col + width - 1] - prefix_row[r][col - 1];
                            }
                        }
                    if (curr_sum <= threshold) {
                        ans = max(ans, width);
                    } else {
                        break;
                    }
                } 
            }
        }
        return ans;
        
    }
};