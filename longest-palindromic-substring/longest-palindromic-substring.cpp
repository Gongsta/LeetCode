class Solution {
public:
    int dp[1001][1001];
    int recur(int l, int r, string& s) {
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        if (l == r) {
            return dp[l][r] = 1;
        } else if (l > r) {
            return dp[l][r] = 0;
        }  else if (l + 1 == r) {
            return dp[l][r] = s[l] == s[r];
        }
        else {
            if (s[l] == s[r]) {
                return dp[l][r] = recur(l+1, r-1, s);
            } else {
                return dp[l][r] = false;
            }
            
        }
        
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        for (int i=0;i<s.size();i++) {
            for (int j=i;j<s.size();j++) {
                recur(i, j, s);
            }
        }
        string longest_s;
        int curr_longest = 0;
        for (int i=0;i<s.size();i++) {
            for (int j=i;j<s.size();j++) {
                if (dp[i][j] == 1 && j-i + 1 > curr_longest) {
                    longest_s = s.substr(i, j-i + 1);
                    curr_longest = j-i + 1;
                }
            }
        }
        return longest_s;
    }
};