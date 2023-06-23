class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            dp[i] = 1;
            for (int j=0;j<i;j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};