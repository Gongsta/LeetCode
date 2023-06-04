class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int diff[n];
        int buckets[100001];
        memset(buckets, 0, sizeof(buckets));
        for (int i=0;i<n;i++) {
            int diff = abs(nums1[i] - nums2[i]);
            buckets[diff]++;
        }
        long long k3 = k1 + k2;
        
        for (int i=100000;i>=1;i--) {
            if (buckets[i] > 0) {
                if (k3 > buckets[i]) {
                    k3 -= buckets[i];
                    buckets[i-1] += buckets[i];
                    buckets[i] = 0;
                } else {
                    buckets[i] -= k3;
                    buckets[i-1] += k3;
                    k3 = 0;
                    break;
                }
            }
        }
        long long ans = 0;
        for (long long i=100000;i>=0;i--) {
            ans += buckets[i] * (i * i);
        }
        
        return ans;
        
        
        
    }
};