class Solution {
public:
    vector<int> solve(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums1_unique;
        int p = 0;
        for (int i = 0;i<nums1.size();i++) {
            while (p < nums2.size() && nums2[p] < nums1[i]) p++;
            // If this number is not seen in nums2
            if (p == nums2.size() || nums2[p] != nums1[i]) {
                // Check for duplicates
                if (nums1_unique.empty() || nums1_unique.back() != nums1[i]) {
                    nums1_unique.push_back(nums1[i]);
                }
            }
        }
        return nums1_unique;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<vector<int>> ans;
        vector<int> nums1_unique = solve(nums1, nums2);
        vector<int> nums2_unique = solve(nums2, nums1);
        ans.push_back(nums1_unique);
        ans.push_back(nums2_unique);
        return ans;

        
    }
};