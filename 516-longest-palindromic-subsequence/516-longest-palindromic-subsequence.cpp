/*
int LPS(string s, int i, int j, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) {
        dp[i][j] = 2 + LPS(s, i+1, j-1, dp);
        return dp[i][j];
    }
    dp[i][j] = max(LPS(s, i+1, j, dp), LPS(s, i, j-1, dp));
    return dp[i][j];
    
}
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));

        return LPS(s, 0, s.length()-1, dp);
        
    }
};
*/
class Solution {
public:
    int recur(int ind1, int ind2, string& s, string& rev, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1]==rev[ind2]) return dp[ind1][ind2]=1+recur(ind1-1, ind2-1, s, rev, dp);
        return dp[ind1][ind2]=max(recur(ind1-1, ind2, s, rev, dp), recur(ind1, ind2-1, s, rev, dp));
    }
    
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recur(n-1, n-1, s, rev, dp);
    }
};