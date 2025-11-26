class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        // Sort and keep a running counter. Ignore duplicates
        sort(nums.begin(), nums.end());

        int ans = 1;
        int curr_seq = 1;

        for (int i = 1;i<nums.size();i++) {
            if (nums[i] == nums[i-1])  {
                continue;
            } else if (nums[i] == nums[i-1] + 1) {
                curr_seq++;
                ans = max(ans, curr_seq);
            } else { // reset
                curr_seq = 1;
            }
        }
        return ans;
    }
};