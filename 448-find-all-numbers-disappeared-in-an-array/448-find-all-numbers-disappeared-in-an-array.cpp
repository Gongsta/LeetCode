class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num: nums) {
            s.insert(num);
        }
        vector<int> ans;
        for (int i=1;i<=nums.size();i++) {
            if (!s.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};