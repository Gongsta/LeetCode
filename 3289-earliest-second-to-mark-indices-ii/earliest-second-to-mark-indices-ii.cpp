class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, long long m) {
        unordered_map<int, int> num_to_idx;
        for (int i =0;i<m;i++) {
            if (!num_to_idx.count(changeIndices[i])) {
                num_to_idx[changeIndices[i]] = i;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;

        int avail = 0;
        for (int i = m-1;i>=0;i--) {
            if (num_to_idx[changeIndices[i]] == i && nums[changeIndices[i] - 1] != 0) {
                pq.push(nums[changeIndices[i] - 1]);
                if (avail > 0) {
                    avail--; // mark as 0
                } else {
                    pq.pop();
                    avail++;
                }
            } else {
                avail++;
            }
        }
        int k = pq.size();
        long long zeroandmark = 2ll * k;
        long long total = accumulate(nums.begin(), nums.end(), 0ll);
        long long pq_sum = 0;
        while (!pq.empty()) {
            pq_sum += pq.top(); pq.pop();
        }
        long long decrementandmark = (nums.size() - k) + (total - pq_sum);

        return decrementandmark + zeroandmark <= m;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int l = 1;
        int r = changeIndices.size();
        int ans = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            cout << mid << endl;
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