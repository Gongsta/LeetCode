class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        // Base cases
        dp[0][1] = 0;
        dp[1][0] = 0;

        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=m;j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1]; // dp[i][j] = mininum path sum passing through (i-1, j-1)
            }
        }
        return dp[n][m];
        
    }
};