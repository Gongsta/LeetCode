class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        vector<int> nums_prefix = nums;
        for (int i=1;i<nums_prefix.size();i++) {
            nums_prefix[i] += nums_prefix[i-1];
        }
        map<int, int> m;
        int curr_longest_i = -1;
        for (int i=0;i<nums.size();i++) {
            if (!m.count(nums[i])) {
                m[nums[i]] = -1;
            }
            int longest = max(curr_longest_i, m[nums[i]]);
            if (longest == -1) {
                sum = max(sum, nums_prefix[i]);
            } else {
                sum = max(sum, nums_prefix[i] - nums_prefix[longest]);
            }
            curr_longest_i = max(curr_longest_i, m[nums[i]]);
            m[nums[i]] = i;

        }

        return sum;
        
    }
};