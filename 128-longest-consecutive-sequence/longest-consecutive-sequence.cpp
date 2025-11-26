class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        // Sort and keep a running counter. Ignore duplicates
        sort(nums.begin(), nums.end());
        int ans = 1;
        int curr = nums[0];
        int curr_seq = 1;
        for (int i = 1;i<nums.size();i++) {
            if (nums[i] == curr) continue;
            if (nums[i] == curr + 1) {
                curr_seq++;
                curr = nums[i];
                ans =max (ans, curr_seq);
            } else {
                curr = nums[i];
                curr_seq = 1;
            }
        }
        return ans;
    }
};