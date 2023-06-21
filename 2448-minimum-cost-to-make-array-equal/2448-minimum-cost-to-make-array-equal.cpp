class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        /* Binary search the number in O(log n) */
        long long min_cost = 1e16;
        int l = 0;
        int r = 1e6;
        while (l <= r) {
            int target_number = (l+r) /2;
            long long curr_cost = 0;
            for (int i=0;i<nums.size();i++) {
                curr_cost += (long long) abs(nums[i] - target_number) * (long long) cost[i];
            }
            long long curr_cost_1 = 0;
            for (int i=0;i<nums.size();i++) {
                curr_cost_1 += (long long) abs(nums[i] - (target_number + 1)) * (long long) cost[i];
            }
            min_cost = min(curr_cost, min_cost);
            if (curr_cost_1 > curr_cost) { // increasing slope
                r = target_number - 1;
            } else {
                l = target_number + 1; // decreasing slope
            }
        }
        return min_cost;
    }
};