class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_n = nums[0];
        int max_n = nums[0];
        int ans = -1;
        for (int num: nums) {
            max_n = max(max_n, num);
            if (max_n - min_n > 0) {
                ans = max(ans, max_n - min_n);
            }
            if (num < min_n) {
                min_n = num;
                max_n = num;
            }
        }
        return ans;
    }
};