class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int total = (nums1.size() + nums2.size());
        int half = (total + 1) / 2;

        int l = 0;
        int r = nums1.size();

        while (l <= r) {
            int mid = (l + r) / 2;
            int mid2 = half - mid;
            int l1 = mid == 0 ?  INT_MIN : nums1[mid - 1];
            int r1 = mid == nums1.size() ? INT_MAX : nums1[mid];
            int l2 = mid2 == 0 ?  INT_MIN : nums2[mid2 - 1];
            int r2 = mid2 == nums2.size() ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 1) return max(l1, l2);
                return ((double)(min(r1, r2)) + (double)(max(l1, l2))) / 2.0;
            } else if (l1 > r2) {
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }
        return 0.0;
    }
};