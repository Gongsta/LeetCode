class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> cnt_to_idx;
        int cnt = 0;
        int ans = 0;
        cnt_to_idx[0] = -1;

        for (int i=0;i<nums.size();i++) {
            int num = nums[i];
            if (num % 2 == 0) {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt_to_idx.count(cnt)) {
                ans = max(ans, i - cnt_to_idx[cnt]);
            } else {
                cnt_to_idx[cnt] = i;
            }
        }
        return ans;

        
    }
};