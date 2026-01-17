class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, int m) {
        unordered_set<int> seen;
        long long need = 0;
        for (int i = m-1;i>=0;i--) {
            if (!seen.count(changeIndices[i] - 1)) {
                seen.insert(changeIndices[i] - 1);
                need += nums[changeIndices[i] - 1];
            } else {
                need--;
                need = max(0ll, need);
            }
        }
        return (need == 0) && (seen.size() == nums.size());

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