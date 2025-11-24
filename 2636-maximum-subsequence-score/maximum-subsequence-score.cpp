class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        /*
        1. Sort the arrays and do computation?

        nums1:  100 100 100 100000000 100 100 .. 1
        nums2:  5    5    5    1       5   5 ... 5

        2. Leverage some sort of DP?

        If the minimum value is k, what is the maximum sum we can get?

        Solution:
        - Store a queue that maps nums2 values to nums1 sums.
        - Iterate of nums2 from highest to lower values
        - keep a running sum of nums1 so far, and multiply by current nums2
        - Answer is max of (answer, nums2 * running_sum);
        */
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0;i<n;i++) {
            nums.push_back({nums2[i], nums1[i]});
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end()); // Larger to smaller values

        long long ans = 0;
        long long nums1_sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate over nums
        for (auto [num2, num1] : nums) {
            nums1_sum += num1;
            pq.push(num1);
            while (pq.size() > k) {
                nums1_sum -= pq.top(); pq.pop();
            }
            // We are only allowed to cmpute answer for a subsequence of length k
            if (pq.size() == k) {
                ans = max(ans, 1ll * nums1_sum * num2);
            }
        }
        return ans;

        
    }
};