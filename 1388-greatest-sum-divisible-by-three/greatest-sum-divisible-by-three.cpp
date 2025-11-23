class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        /*
        dp[(r + num) % 3] = max(dp[(r + num) % 3], dp[r] + num));
        return dp 0,
        */
        vector<int> dp = {0, INT_MIN, INT_MIN};
        vector<int> prev;
        for (int num: nums) {
            prev = dp;
            for (int r = 0;r<3;r++) {
                dp[(r+num) % 3] = max(dp[(r+num) % 3], prev[r] + num);
            }
        }
        return dp[0];
    }
};