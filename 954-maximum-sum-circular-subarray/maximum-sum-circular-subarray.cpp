class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = nums[0];
        int curMax = 0;
        int curMin = 0;
        int bestMax = nums[0];
        int bestMin = nums[0];
        int total = accumulate(nums.begin(), nums.end(), 0);
        for (int num: nums) {
            if (curMax < 0) curMax = 0;
            if (curMin > 0) curMin = 0;
            curMax += num;
            curMin += num;
            bestMax = max(bestMax, curMax);
            bestMin = min(bestMin, curMin);
        }
        if (bestMax < 0) return bestMax;

        return max(bestMax, total - bestMin);
    }
};