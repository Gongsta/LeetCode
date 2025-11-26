class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        /*
        dp[i][j][k] = # of paths that can reach cell (m-1, n - 1) with remainder k

        dp[i][j][k] = dp[i+1][j][k - grid[i][j]] + dp[i][j+1][k - grid[i][j]];
        return dp[0][0][k]

        itreate from i = m -1 to 0
            itreate from j = n -1 to 0
                itreate from w = 0 to w = k

                target = grid[i][j] + sum....
                (target - grid[i][j]) = sum
        */
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, 0)));
        int MOD = (int)1e9 + 7;
        for (int i = m -1 ;i>=0;i--) {
            for (int j = n -1 ;j>=0;j--) {
                for (int l=0;l<k;l++) {
                    int diff = l -  (grid[i][j] % k);
                    diff = (diff + k) % k;
                    if (i == m -1 && j == n -1)  {dp[i][j][grid[i][j] % k] = 1;}
                    else if (i == m - 1) {
                        dp[i][j][l] += dp[i][j+1][diff];
                    } else if (j == n-1) {
                        dp[i][j][l] += dp[i+1][j][diff];
                    } else {
                        dp[i][j][l] = dp[i][j+1][diff] + dp[i+1][j][diff];
                    }
                    dp[i][j][l] %= MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};