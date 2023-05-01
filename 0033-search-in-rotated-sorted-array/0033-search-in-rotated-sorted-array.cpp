class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        // Search for the pivot
        int first_value = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[0]) {
                r = mid - 1;
                first_value = mid;
            } else {
                l = mid + 1;
            }
        }
        l = first_value;
        r = first_value + nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid % nums.size()] == target) {
                return mid % nums.size();
            } else if (nums[mid % nums.size()] < target) {
                l = mid + 1;
                
            } else {
                r = mid - 1;
            }
            
        }
        return -1;
        
        
    }
};