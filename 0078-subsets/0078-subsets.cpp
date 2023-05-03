class Solution {
public:
    vector<int> subset;
    vector<vector<int>> subsets_vec;
    void search(vector<int>& nums, int i, int n) {
        if (i == n) {
            subsets_vec.push_back(subset);
            return;
        }
        search(nums, i+1, n);
        subset.push_back(nums[i]);
        search(nums, i+1, n);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subsets_vec.clear();
        search(nums, 0, nums.size());
        return subsets_vec;
        
        
    }
};