class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        long long start = nums[0];
        long long length = 1;
        for (int i = 1;i<=nums.size();i++) {
            if (i < nums.size() && nums[i] == nums[i-1] + 1) {
                length++;
            } else {
                if (length == 1) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(start + length - 1));
                }

                if (i < nums.size()) {
                    start = nums[i];
                    length = 1;
                }
            }
        }
        return ans;
        
    }
};