class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int dp[n+1][m+1];
        int ans = INT_MIN;
        for (int i = n;i>=0;i--) {
            for (int j = m;j>=0;j--) {
                if (i == n || j == m) {
                    dp[i][j] = INT_MIN;
                } else {
                    int num = nums1[i] * nums2[j];
                    if (dp[i+1][j+1] > 0) num += dp[i+1][j+1];
                    dp[i][j] = max(num, max(dp[i+1][j], dp[i][j+1]));
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
        
    }
};