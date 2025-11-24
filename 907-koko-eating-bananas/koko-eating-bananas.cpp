class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            // Check if this value works
            long long h_required = 0;
            for (int pile: piles) {
                h_required += ((long long)pile + mid - 1)/mid;
            }

            // Update bounds
            if (h_required <= h) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};