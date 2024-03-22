class Solution {
public:
    int twoEggDrop(int n) {
        int k = 2;
        int dp[k + 1][n+1];
        for (int i=1;i<=n;i++) {
            dp[1][i] = i;
        }
        for (int x=2;x<=k;x++) {
            for (int i=1;i<=n;i++) {
                dp[x][i] = i;
                for (int j=2;j<i;j++) {
                    dp[x][i] = min(1 + max(dp[x-1][j - 1], dp[x][i - j]), dp[x][i]);
                }
            }
        }
        return dp[k][n];
    }
};