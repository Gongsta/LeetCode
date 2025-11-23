class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int mod_0 = 0;
        int mod_1 = -1e9;
        int mod_2 = -1e9;
        for (int num: nums) {
            int prev_mod_0 = mod_0;
            int prev_mod_1 = mod_1;
            int prev_mod_2 = mod_2;
            if (num % 3 == 0) {
                mod_0 = max(max(prev_mod_0, prev_mod_0 + num), num);
                mod_1 = max(prev_mod_1, prev_mod_1 + num);
                mod_2 = max(prev_mod_2, prev_mod_2 + num);
            } else if (num % 3 == 1) {
                mod_0 = max(prev_mod_0, prev_mod_2 + num);
                mod_1 = max(max(prev_mod_1, prev_mod_0 + num), num);
                mod_2 = max(prev_mod_2, prev_mod_1 + num);
            } else {
                mod_0 = max(prev_mod_0, prev_mod_1 + num);
                mod_1 = max(prev_mod_1, prev_mod_2 + num);
                mod_2 = max(max(prev_mod_2, prev_mod_0 + num), num);
            }
        }
        return mod_0;
    }
};