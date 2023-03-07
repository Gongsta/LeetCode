class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int i = 0;
        int l = 0;
        int curr_sum = 0;
        while (i + l < nums.size()) {
            curr_sum += nums[i+l];
            ans = max(ans, curr_sum);
            if (curr_sum <= 0) {
                curr_sum = 0;
                l = l+i + 1;
                i = 0;
            } else {
                i++;
            }
        }
           
        return ans;
        
    }
};