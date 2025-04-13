class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int l1 =  0;
        int l2 = 0;
        vector<vector<int>> ans;
        while (l1 < nums1.size() || l2<nums2.size()) {
            if (l1 == nums1.size()) {
                ans.push_back(nums2[l2]);
                l2++;
            } else if (l2 == nums2.size()) {
                ans.push_back(nums1[l1]);
                l1++;
            } else {
                if (nums1[l1][0] == nums2[l2][0]) {
                    ans.push_back({nums1[l1][0], nums1[l1][1] + nums2[l2][1]});
                    l1++;
                    l2++;
                } else if (nums1[l1][0] < nums2[l2][0]) {
                ans.push_back(nums1[l1]);
                l1++;
                } else {
                ans.push_back(nums2[l2]);
                l2++;
                }
            }
        }
        return ans;
        
    }
};