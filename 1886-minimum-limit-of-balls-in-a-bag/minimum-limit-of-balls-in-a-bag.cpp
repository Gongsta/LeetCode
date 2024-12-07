class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 1;
        int r = nums[n-1];
        int ans = r;
        while (l <= r) {
            int mid = (l+ r) / 2;
            int num_ops = 0;
            for (int i=0;i<n;i++) {
                if (nums[i] > mid) {
                    num_ops += ceil(((double)nums[i] / (double)mid) - 1);
                }
            }
            cout << l << " " << r << endl;
            if (num_ops > maxOperations) {
                l = mid + 1;
            } else {
                ans = min(mid, ans);
                r = mid - 1;
            }
        }
        return ans;
    }
};