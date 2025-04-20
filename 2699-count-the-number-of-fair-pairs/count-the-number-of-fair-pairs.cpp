class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0;i<nums.size();i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            long long smallest = nums.size();
            long long largest = i - 1;
            while (l <= r) {
                long long mid = (l + r) / 2;
                int sum = nums[i] + nums[mid];
                if (sum < lower) {
                    l = mid + 1;
                } else if (sum > upper) {
                    r = mid  -  1;
                } else {
                    largest = max(largest, mid);
                    l = mid + 1;
                }
            }
             l = i + 1;
            r = nums.size() - 1;
            while (l <= r) {
                long long mid = (l + r) / 2;
                int sum = nums[i] + nums[mid];
                if (sum < lower) {
                    l = mid + 1;
                } else if (sum > upper) {
                    r = mid  -  1;
                } else {
                    smallest = min(smallest, mid);
                    r = mid - 1;
                }
            }
            cout << i << " " << largest << " " << smallest << endl;
            if (largest == i - 1 || smallest == nums.size()) continue;
            ans += (largest - smallest + 1);
        }
        return ans;
        
    }
};