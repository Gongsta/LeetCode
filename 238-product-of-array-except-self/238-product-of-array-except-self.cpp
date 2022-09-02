class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix[n];
        int suffix[n];
        for (int i=0;i<nums.size();i++) {
            if (i == 0) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = nums[i] * prefix[i-1];
            }
        }
        for (int i=nums.size()-1;i>=0;i--) {
            if (i == nums.size()-1) {
                suffix[i] = nums[i];
            } else {
                suffix[i] = nums[i] * suffix[i+1];
            }
        }
        vector<int> ans;
        for (int i=0;i<nums.size();i++) {
            if (i == 0) {
                ans.push_back(suffix[i+1]);
            } else if (i == nums.size()-1) {
                ans.push_back(prefix[i-1]);
            } else {
                ans.push_back(prefix[i-1] * suffix[i+1]);
            }
        }
        return ans;
        
    }
};