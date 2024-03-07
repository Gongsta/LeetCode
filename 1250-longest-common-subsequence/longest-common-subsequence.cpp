class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        int ans = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (text1[i] == text2[j]) {
                    // Use the matching character
                    dp[i+1][j+1] = max(dp[i][j] + 1, dp[i+1][j+1]);
                    ans = max(ans, dp[i+1][j+1]);
                } else {
                    // Move on
                    dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
                    dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
                }
            }
        }
        return ans;


        
    }
};