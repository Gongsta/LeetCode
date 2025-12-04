class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        int odd = 0;
        int ans = 0;
        for (int num: nums) {
            if (num % 2 == 1) {
                odd++;
            }
            int need = odd - k;
            ans += cnt[need];
            cnt[odd]++;
        }
        return ans;
    }
};