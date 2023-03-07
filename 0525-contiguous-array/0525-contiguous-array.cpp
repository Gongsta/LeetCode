class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        map<int, int> first;
        first[0] = -1;
        int longest = 0;
        for (int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
        }
        for (int i=0;i<nums.size();i++) {
            if (first.count(nums[i])) {
                longest = max(longest, i - first[nums[i]]);
            } else {
                first[nums[i]] = i;
            }
            
        }
        return longest;
        
        
    }
};