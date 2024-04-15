class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target_sum = 0;
        for (int num: nums) {
            target_sum += num;
        }
        if (target_sum % 2 == 1) return false;
        target_sum /= 2;
        set<int> s;
        s.insert(target_sum);
        for (int num: nums) {
            if (s.count(num)) return true;
            for (auto x: s) {
                s.insert(x - num);
            }
        }
        return false;
    }
};