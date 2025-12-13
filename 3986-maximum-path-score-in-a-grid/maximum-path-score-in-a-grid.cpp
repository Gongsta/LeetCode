class Solution {

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k = min(k, n-1 + m -1);

        int dp[n+1][m+1][k+1];
        for (int i = 0;i<=n;i++) {
            for (int j = 0;j<=m;j++) {
                for (int curr_k = 0;curr_k<=k;curr_k++) {
                    dp[i][j][curr_k] = INT_MIN;
                }
            }
        }

        dp[0][0][k - min(grid[0][0], 1)] = grid[0][0]; // score
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                int cost = min(grid[i][j], 1);
                for (int curr_k = 0;curr_k<=k;curr_k++) {
                    if (curr_k - cost < 0) continue; // not allowed to reach this state
                    if (dp[i][j][curr_k] != INT_MIN) { // this state is reachable
                        dp[i+1][j][curr_k - cost] = max(dp[i+1][j][curr_k-cost], dp[i][j][curr_k] + grid[i][j]);
                        dp[i][j+1][curr_k - cost] = max(dp[i][j+1][curr_k-cost], dp[i][j][curr_k] + grid[i][j]);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int curr_k = 0;curr_k<=k;curr_k++) {
            ans = max(ans, dp[n][m-1][curr_k]);
        }
        if (ans == INT_MIN) return -1;
        return ans;

    }
};