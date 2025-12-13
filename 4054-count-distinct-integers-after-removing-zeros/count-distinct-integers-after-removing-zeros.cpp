class Solution {
public:
    long long countDistinct(long long n) {
        /*
        Counting number of numbers without 0
        */
        string s = to_string(n);
        int L = s.length();
        vector<long long> dp(L, 1);
        long long ans = 0;
        for (int i = 1;i<L;i++) {
            dp[i] = 9 * dp[i-1];
            // Add to ans
            ans += dp[i];
        }
        // For string of length L
        for (int i = 0;i<L;i++) {
            int d = s[i] - '0';
            if (d == 0) return ans; // not possible to get anymore
            int remaining_length = L - i - 1;
            ans += (d - 1) * dp[remaining_length];
        }
        ans++; // for the number n
        return ans;


        
    }
};