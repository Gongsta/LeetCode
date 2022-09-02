class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (true) {
            i = nums[i];
            j = nums[nums[j]];
            if (i == j) break;
        }
        int i2 = 0;
        while (true) {
            i2 = nums[i2];
            i = nums[i];
            if (i == i2) {
                return i;
            }
              
            
        }
    }
};