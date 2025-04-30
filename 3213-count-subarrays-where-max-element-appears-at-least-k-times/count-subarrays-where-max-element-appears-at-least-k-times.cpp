class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l = -1;
        int max_num = *max_element(nums.begin(), nums.end());
        for (int i =0;i<nums.size();i++) {
            if (nums[i] == max_num) {
                l = i;
                break;
            }
        }
        int r = l;
        int curr_k = 1;
        for (int i =r + 1;i<nums.size();i++) {
            if (k == curr_k) break;
            if (nums[i] == max_num) {
                r = i;
                curr_k++;
            }
        }
        if (curr_k < k) return 0;
        int prev_l = l;
        long long ans = (l + 1) * (nums.size() - r);
        l++;
        r++;
        while (l < nums.size() && r < nums.size()) {
            while ( l < nums.size() && nums[l] != max_num) {
                l++;
            }
            while (r < nums.size() && nums[r] != max_num) {
                r++;
            }
            if (l == nums.size() || r == nums.size()) break;
            ans += (l - prev_l) * (nums.size() - r);
            prev_l = l;
            l++;
            r++;
        }
        return ans;
    }
};