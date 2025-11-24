class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int num: nums) {
            if (cnt[k - num] > 0) {
                ans++;
                cnt[k-num]--;
            } else {
                cnt[num]++;
            }
        }
        return ans;
    }
};