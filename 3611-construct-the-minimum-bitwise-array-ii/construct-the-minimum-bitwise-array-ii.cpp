class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        /*
        111
        011

        */
        vector<int> ans;
        for (int num: nums) {
            int num_ones = 0;
            int num_copy = num;
            while (num_copy > 0) {
                if ((num_copy & 1) == 1) {
                    num_ones++;
                } else {
                    break;
                }
                num_copy >>= 1;
            }
            if (num_ones == 0) {
                ans.push_back(-1);
            } else {
                int bitmask = (1 << num_ones) - 1;
                int add =(1 << (num_ones - 1)) - 1;
                ans.push_back(num - (num & bitmask) + add);
            }
        }
        return ans;
        
    }
};