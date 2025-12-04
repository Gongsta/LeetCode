class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> cnt(nums.size() + 1, 0);
        cnt[0] = 1;

        int odd = 0;
        int ans = 0;
        for (int num: nums) {
            if (num % 2 == 1) {
                odd++;
            }
            int need = odd - k;
            if (need >= 0) ans += cnt[need];
            cnt[odd]++;
        }
        return ans;
    }
};