class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m+1, INT_MAX);
        // Base cases
        dp[1] = 0;

        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=m;j++) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i-1][j-1]; // dp[j] = mininum path sum passing through (i-1, j-1)
            }
        }
        return dp[m];
        
    }
};