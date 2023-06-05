class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* Works but too slow
        int ans = 0;
        for (int i=1;i<nums.size() - ans;i++) {
            while (nums[i] == nums[i-1]) {
                ans++;
                int j = i;
                while (j < nums.size() - 1 && nums[j] <= nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    j++;
                }
            }
        }
        return nums.size() - ans;
        */
        int unique_p = 0;
        int curr_p = 0;
        int curr_num = nums[curr_p];
        while (unique_p < nums.size()) {
            while (nums[unique_p] == nums[curr_p]) {
                unique_p++;
                if (unique_p >= nums.size()) {
                    break;
                }
            }
            if (unique_p >= nums.size()) {
                break;
            }
            curr_p++;
            swap(nums[unique_p], nums[curr_p]);
            unique_p++;
        }
        return curr_p + 1;

    }
};