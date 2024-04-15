class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        int dp[nums.size()];
        for (int i=0;i<nums.size();i++) {
            dp[i] = 1;
            for (int j=0;j<i;j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};