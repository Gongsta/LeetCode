class Solution {
public:
    long long prefix_sum(vector<long long>& prefix, int l, int r) {
        if (l == 0) {
            return prefix[r];
        }
        return prefix[r] - prefix[l-1];
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> dp(nums.size(), 0);
        vector<long long> prefix(nums.size(), 0);
        
        prefix[0] = nums[0];
        for (int i =1;i<nums.size();i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        for (int i =0;i<nums.size();i++) {
            dp[i] = -1e9;
        }
        
        long long ans = -1e9;

        dp[k-1] = prefix_sum(prefix, 0, k - 1);
        ans = dp[k-1];
        for (int i=k;i<nums.size();i++) {
            long long sum = prefix_sum(prefix, i - k + 1, i);
            dp[i] = max(sum, sum + dp[i-k]);
            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};