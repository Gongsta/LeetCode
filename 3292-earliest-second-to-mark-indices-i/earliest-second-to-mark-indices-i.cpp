class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, int m) {
        vector<bool> seen(nums.size(), false);
        long long need = 0;
        for (int i = m-1;i>=0;i--) {
            if (!seen[changeIndices[i] - 1]) {
                seen[changeIndices[i] - 1] = true;
                need += nums[changeIndices[i] - 1];
            } else {
                need--;
                need = max(0ll, need);
            }
        }
        return (need == 0) && (accumulate(seen.begin(), seen.end(), 0) == nums.size());

    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int l = 1;
        int r = changeIndices.size();
        int ans = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isPossible(nums, changeIndices, mid)) {
                ans = min(ans, mid);
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
        
    }
};