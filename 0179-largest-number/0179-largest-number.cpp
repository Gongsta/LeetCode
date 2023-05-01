class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Intuition: Just put the larger values first
        // Use our own storing algorithm
        vector<string> nums_string;
        for (int num: nums) {
            nums_string.push_back(to_string(num));
        }
        for (int i=0;i<nums_string.size();i++) {
            int smallest_i = i;
            for (int j=i+1;j<nums_string.size();j++) {
                if (greater_custom(nums_string[j], nums_string[smallest_i])) {
                    smallest_i = j;
                }
            }
            swap(nums_string[i], nums_string[smallest_i]);
        }
        
        string ans;
        for (string s: nums_string) {
            if (ans.size() == 1 && ans[0] == '0' && s == "0")  {
                continue;
            }
            ans += s;
        }
        return ans;
        
    }
    bool greater_custom(string s1, string s2) {
        if (s1 + s2 > s2 + s1) {
            return true;
        } else {
            return false;
        }

    }
};