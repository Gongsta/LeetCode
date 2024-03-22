class Solution {
public:
    int twoEggDrop(int n) {
        int num_eggs = 2;
        int dp[num_eggs + 1][n+1];
        for (int i=1;i<=n;i++) {
            dp[1][i] = i;
        }
        for (int k=2;k<=num_eggs;k++) {
            for (int i=1;i<=n;i++) {
                dp[k][i] = i;
                for (int j=1;j<=i/2;j++) {
                    dp[k][i] = min(1 + max(dp[k-1][j], dp[k][i - j - 1]), dp[k][i]);
                }
            }
        }
        return dp[2][n];
    }
};