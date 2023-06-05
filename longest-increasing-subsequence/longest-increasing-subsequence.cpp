class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = 1;
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i=1;i<nums.size();i++) {
            for (int j=0;j<i;j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
        
    }
};