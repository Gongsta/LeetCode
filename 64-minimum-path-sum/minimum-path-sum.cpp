class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=m;j++) {
                if (i == 1) {
                    dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
                } else if (j == 1) {
                    dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1]; // dp[i][j] = mininum path sum passing through (i-1, j-1)
                }
            }
        }
        return dp[n][m];
        
    }
};