class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i=0;i<32;i++) {
            int bit = 1 << i;
            int count = 0;
            for (int num: nums) {
                if (num & bit) {
                    count++;
                }
            }
            count %= 3;
            ans += count << i;
        }
        return ans;
    }
};