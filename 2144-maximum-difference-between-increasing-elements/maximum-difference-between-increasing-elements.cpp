class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        for (int i=0;i<nums.size(); i++) {
            for (int j=0;j<i;j++) {
                if (nums[j] < nums[i]) {
                    ans = max(ans, nums[i] - nums[j]);
                }
            }
        }
        return ans;
    }
};