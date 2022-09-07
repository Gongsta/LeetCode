class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long sum = (n+1) * n / 2;
        long long curr_sum = 0;
        for (auto num: nums) {
            curr_sum += num;
        }
        return sum - curr_sum;
        
    }
};