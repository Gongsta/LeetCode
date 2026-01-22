class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int min_sum = INT_MAX;
        int min_idx;
        bool non_decreasing = true;
        for (int i = 1;i<nums.size();i++) {
            if (nums[i] < nums[i-1]) non_decreasing = false;
            if (nums[i] + nums[i-1] < min_sum) {
                min_sum = nums[i] + nums[i-1];
                min_idx = i;
            }
        }
        if (non_decreasing) return 0;
        vector<int> new_nums;
        for (int i=0;i<nums.size();i++) {
            if (i == min_idx - 1) {
                continue;
            } else if (i == min_idx) {
                new_nums.push_back(nums[i] + nums[i-1]);
            } else {
                new_nums.push_back(nums[i]);
            }
        }
        return 1 + minimumPairRemoval(new_nums);
    }
};