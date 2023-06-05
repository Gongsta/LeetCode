class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int a[nums.size()];
        for (int i=0;i<nums.size();i++) {
            a[(i+k) % nums.size()] = nums[i];
        }
        for (int i=0;i<nums.size();i++) {
            nums[i] = a[i];
        }
        
        
    }
};