class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = 0;
        int curr_sum = nums[0];
        int l = 0;
        int r = 0;
        while (l< nums.size()  && r < nums.size()) {
            if (curr_sum < target) {
                r++;
                if (r < nums.size()) {
                    curr_sum += nums[r];
                }
            } else if (curr_sum >= target) {
                if (min_length == 0) {
                    min_length = r - l + 1;
                } else {
                    min_length = min(min_length, r - l + 1);
                }
                
                curr_sum -= nums[l];
                l++;
                if (l > r) {
                    r = l;
                }
            }
        }
        return min_length;
    }
};