class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        int n = nums.size();
        for (int read = 0; read < n;read++) {
            if (nums[read] != 0) { // write it to the location
                swap(nums[write], nums[read]);
                write++;
            }
        }
    }
};