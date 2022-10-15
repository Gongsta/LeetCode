int dp[1000][1000];
int longestDP(int l, int r, string &s) {
    if (l > r) return 0;
    if (l == r) return 1;
    if (dp[l][r] != 0) {
        return dp[l][r];
    }
    if (s[l] == s[r]) {
        return dp[l][r] = 2 + longestDP(l+1, r-1, s);
    } else {
        return dp[l][r] = max(longestDP(l+1, r, s), longestDP(l, r-1, s));
    }
}
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        memset(dp, 0, sizeof(dp));
        return longestDP(0, s.length()-1, s);
    }
};