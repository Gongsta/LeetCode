class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int suffix_sum = 0;
        for (int num: nums) {
            suffix_sum += num;
        }
        int prefix_sum = 0;
        for (int i = 0;i< nums.size();i++) {
            suffix_sum -= nums[i];
            if (i > 0) prefix_sum += nums[i-1];
            if (prefix_sum == suffix_sum) {
                return i;
            }

        }
        return -1;
        
    }
};