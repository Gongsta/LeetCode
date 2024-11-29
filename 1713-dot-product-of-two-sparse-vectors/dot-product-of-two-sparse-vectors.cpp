class SparseVector {
public:
    map<int, int> m;
    
    SparseVector(vector<int> &nums) {
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0) {
                m[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for (auto x: m) {
            if (vec.m.count(x.first)) {
                ans += x.second * vec.m[x.first];
            }
        }
        return ans;
        
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);