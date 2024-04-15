class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // make 1-indexed
        int n = text1.size();
        int m = text2.size();
        text1 = " " + text1;
        text2 = " " + text2;
        int dp[n+1][m+1];
        for (int i=0;i<=n;i++)  {
            for (int j=0;j<=m;j++) {
                if (i == 0 || j == 0)  {
                    dp[i][j] = 0;
                } else {
                    if (text1[i] == text2[j]) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
                }
            }
        }
        return dp[n][m];

        
    }
};