class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        
        // Two pointer method, can also do binary search each value
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int nums1_p = 0;
        int nums2_p = 0;
        while (nums1_p < nums1.size() && nums2_p < nums2.size()) {
            if (nums1[nums1_p] == nums2[nums2_p]) {
                ans.push_back(nums1[nums1_p]);
                nums1_p++;
                nums2_p++;
            } else if (nums1[nums1_p] < nums2[nums2_p]) {
                nums1_p++;
            } else {
                nums2_p++;
            }
        }
        return ans;
        
    }
};