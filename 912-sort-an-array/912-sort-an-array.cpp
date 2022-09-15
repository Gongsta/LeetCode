class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Counting sort
        vector<int> ans;
        map<int, int> m;
        for (auto num: nums) {
            m[num]++;
            
        }
        for (auto x: m) {
            for (int i=0;i<x.second; i++) {
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};