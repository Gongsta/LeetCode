class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> s;
        map<int, int> m;
        vector<int> v;
        for (int i=0;i<nums.size();i++) {
            if (s.count(nums[i])) {
            v.push_back(i); v.push_back(m[target-nums[i]]); 
            break;
}
            m[nums[i]] = i;
            s.insert(target-nums[i]);
        }
        return v;
        
    }
};