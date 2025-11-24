class Solution {
    map<pair<int, int>, int> memo;
public:
    int uniquePaths(int m, int n) {
        /*
        dp[m][n] = dp[m][n-1] + dp[m-1][n]
        */
        int dp[m+1][n+1];
        for (int i = 1;i<=m;i++) {
            for (int j = 1;j<=n;j++) {
                if (i == 1 || j == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j-1];;
                }
            }
        }
        return dp[m][n];
    }
};