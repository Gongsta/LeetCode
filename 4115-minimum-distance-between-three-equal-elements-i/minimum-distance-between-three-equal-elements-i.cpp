class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> num_to_pos;
        for (int i = 0;i<nums.size();i++) {
            num_to_pos[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto& [num, pos]: num_to_pos) {
            for (int i = 0;i<(int)pos.size() - 2;i++) {
                ans = min(ans, 2 * (pos[i+2] - pos[i]));
            }
        }
        if (ans ==INT_MAX) return -1;
        return ans;
        
    }
};