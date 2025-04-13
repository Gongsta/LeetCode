class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (nums[0] < k) return -1;
        if (nums.size() == 1) return nums[0] != k;
        int ans = nums[0] != k;
        for (int i = nums.size() - 2;i>=0;i--) {
            if (nums[i] != nums[i+1]) {
                ans++;
            }
        }
        return ans;
        
    }
};