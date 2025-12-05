class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n - 1;
        int write = n + m - 1;
        while (i >=0 || j >=0){
            if (i == - 1) {
                nums1[write] = nums2[j];
                j--;
            } else if (j == -1 || nums1[i] > nums2[j]) {
                nums1[write] = nums1[i];
                i--;
            } else {
                nums1[write] = nums2[j];
                j--;
            }
            write--;
        }
        
    }
};