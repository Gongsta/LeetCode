class Solution {
public:
    int dp[101][101];
    bool solve(string& s1, string& s2, string& s3, int s1_start, int s2_start) {
        if (dp[s1_start][s2_start] != -1) {
            return dp[s1_start][s2_start];
        }
        int s3_start = s1_start + s2_start;
        bool works = false;
        if (s1_start == s1.size() && s2_start == s2.size() && s3_start == s3.size()) {
            return dp[s1_start][s2_start] = true;
        }
        if (s3_start == s3.size()) {
            return dp[s1_start][s2_start] = false;
        }
        bool found = false;
        if (s1_start != s1.size()) {
            if (s1[s1_start] == s3[s3_start]) {
                works = works || solve(s1, s2, s3, s1_start+1, s2_start);
                found = true;
            }
        }
        if (s2_start != s2.size()) {
            if (s2[s2_start] == s3[s3_start]) {
                works = works || solve(s1, s2, s3, s1_start, s2_start+1);
                found = true;
            }
        }
        if (!found) {
            return dp[s1_start][s2_start] = false;
        }
        
        return dp[s1_start][s2_start] = works;
            
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0);
    }
};

