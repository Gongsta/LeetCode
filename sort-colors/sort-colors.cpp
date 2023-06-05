class Solution {
public:
    void sortColors(vector<int>& nums) {

        // Put 0 in place
        int target = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[target]);
                target++;
            }
        }
        int start = target;
        target = nums.size() - 1;
        while (start < target) {
            while (target >= 0 && nums[target] == 2) {
                target--;
            } 
            if (target < 0) break;
            if (nums[start] == 2 && start < target) {
                swap(nums[start], nums[target]);
                target--;
            }
            start++;
        }
        
            
        /* O(n^2) Solution
        for (int i=0;i<nums.size();i++) {
            int val = nums[i];
            int to_swap = i;
            for (int j=i+1;j<nums.size();j++) {
                if (nums[j] < val) {
                    val = nums[j];
                    to_swap = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[to_swap];
            nums[to_swap] = temp;
        }
        */
    }
};