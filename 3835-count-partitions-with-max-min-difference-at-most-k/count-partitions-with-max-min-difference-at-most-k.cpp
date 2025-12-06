class Solution {
    int MOD = (int)1e9 + 7;
public:
    int prefix_sum(const vector<int>& prefix, int l, int r) {
        if (l == 0) return prefix[r];
        return ((prefix[r] - prefix[l-1]) + MOD) % MOD;
    }

    int countPartitions(vector<int>& nums, int k) {
        /*
        Get the maximum window. Any partition of that works is good. Keep the sliding window

        Find the l such that max (maxdq.front()) - min (mindq.front()) is satisfied.

        Once we find l, just use the prefix sum.

        We can compute the dp[i] = sum(dp[i-1], dp[i+1])
        */
        vector<int> dp(nums.size(), 0);
        vector<int> dp_prefix(nums.size(), 0);
        dp[0] = 1;
        dp_prefix[0] = 1;
        deque<int> maxdq; // holds the max value at the current index
        deque<int> mindq; 
        maxdq.push_back(0);
        mindq.push_back(0);
        int l = 0;

        for (int r = 1;r<nums.size();r++) {
            while (!maxdq.empty() && nums[r] >= nums[maxdq.back()]) maxdq.pop_back();
            while (!mindq.empty() && nums[r] <= nums[mindq.back()]) mindq.pop_back();
            maxdq.push_back(r);
            mindq.push_back(r);
            while (nums[maxdq.front()] - nums[mindq.front()] > k) {
                if (maxdq.front() == l) maxdq.pop_front();
                if (mindq.front() == l) mindq.pop_front();
                l++;
            }
            if (l == 0) {
                dp[r] = 1 + prefix_sum(dp_prefix, 0, r - 1);

            } else {
            dp[r] = prefix_sum(dp_prefix, l-1, r - 1); // sum from dp[l-1] to dp[r-1]

            }
            dp[r] %= MOD;
            dp_prefix[r] = (dp_prefix[r-1] + dp[r]) % MOD;
        }
        return dp[nums.size()-1];
    }
};