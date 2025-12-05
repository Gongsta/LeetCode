class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int left = mid == 0 ? INT_MIN : nums[mid - 1];
            int right = mid == nums.size() - 1 ? INT_MIN : nums[mid+1];
            if (nums[mid] > left && nums[mid] > right) return mid;
            if (left > nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0; // should never run
        
    }
};