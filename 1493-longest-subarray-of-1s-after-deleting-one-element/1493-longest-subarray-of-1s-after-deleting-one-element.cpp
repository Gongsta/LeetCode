class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> ans;
        int count = 0;
        bool has_zero = false;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 0) has_zero =true;
            if (i > 0 && i < nums.size() - 1 && nums[i-1] == 0 && nums[i] == 0 && nums[i+1] == 1) {
               ans.push_back(0);
            } else if (nums[i] == 0) {
                ans.push_back(count);
                count = 0;
            } else if (nums[i] == 1) {
                count++;
            }
        }
        
        if (count != 0) {
            ans.push_back(count);
        }
        
        if (has_zero) {
            int a = ans[0];
            for (int i=1;i<ans.size();i++) {
                a = max(a, ans[i] + ans[i-1]);
            }
            return a;
            
        } else {
            return ans[0] - 1;
        }
        
    }
};