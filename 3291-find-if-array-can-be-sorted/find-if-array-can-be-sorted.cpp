class Solution {
public:
    int num_bits(int x) {
        int num = 0;
        while (x > 0) {
            if (x & 1) {
                num++;
            }
            x = x >> 1;
        }
        return num;
    }
    bool can_swap(int x, int y) {
        return num_bits(x) == num_bits(y);
    }

    bool canSortArrayReverse(vector<int> nums) {
        /*
        We do swap select, 
        */
        for (int i=0;i<nums.size();i++) {
            for (int j=nums.size() - 1;j>i;j--) {
                if (nums[j] < nums[j-1] && can_swap(nums[j], nums[j-1])) {
                    swap(nums[j], nums[j-1]);
                }
            }
        }
        for (int i=0;i<nums.size() -1 ;i++) {
            if (nums[i] > nums[i+1]) return false;
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        /*
        We do swap select, 
        */
        if (canSortArrayReverse(nums)) return true;
        for (int i=0;i<nums.size();i++) {
            for (int j=i;j<nums.size() - 1;j++) {
                if (nums[j] > nums[j+1] && can_swap(nums[j], nums[j+1])) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        for (int i=0;i<nums.size() -1 ;i++) {
            if (nums[i] > nums[i+1]) return false;
        }
        return true;
        
    }
};