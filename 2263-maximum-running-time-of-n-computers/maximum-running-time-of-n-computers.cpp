class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 1;
        long long r = 1e18;
        long long ans = 0;
        sort(batteries.begin(), batteries.end());
        reverse(batteries.begin(), batteries.end());
        while (l <= r) {
            long long mid = (l + r) / 2;
            int i = 0;
            long long curr_charge = 0;
            for (long long battery: batteries) {
                long long prev_charge = curr_charge;
                curr_charge += battery;
                if (curr_charge >= mid) {
                    curr_charge = min(prev_charge, curr_charge % mid);
                    i++;
                }
            }
            if (i >= n) {
                l = mid + 1;
                ans = max(ans, mid);
            } else {
                r = mid - 1;
            }
        }
        return ans;
        
    }
};