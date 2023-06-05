class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto x: m) {
            pq.push({x.second, x.first});
        }
        vector<int> ans;
        for (int i=0;i<k;i++)  {
            pair<int,int> p = pq.top(); pq.pop();
            ans.push_back(p.second);
        }
        return ans;
        
    }
};