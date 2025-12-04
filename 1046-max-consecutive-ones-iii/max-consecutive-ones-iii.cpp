class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        for (int r = 0;r<nums.size();r++) {
            if (nums[r] == 0) k--;
            // Increment l until this valid window
            while (k < 0 && l < nums.size()) {
                if (nums[l] == 0) {
                    k++;
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
        
    }
};