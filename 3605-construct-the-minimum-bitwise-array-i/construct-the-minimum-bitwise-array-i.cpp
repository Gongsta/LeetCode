class Solution {
public:
    int trailing_ones(int x) {
        int ones = 0;
        while (x > 0) {
            if (x & 1) {
                ones++;
            } else {
                break;
            }
            x >>= 1;
        }
        return ones;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            int k = trailing_ones(num);
            if (k == 0) {
                ans.push_back(-1);
            } else {
                int mask = (1 << k) - 1;
                int add = (1 << (k - 1)) - 1;
                ans.push_back((num & ~mask) | add);
            }
        }
        return ans;
        
    }
};