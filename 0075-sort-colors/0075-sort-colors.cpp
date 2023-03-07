class Solution {
public:
    void sortColors(vector<int>& nums) {

        // O(n^2) Solution
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
    }
};