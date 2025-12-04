class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        Store prefix
        As you iterate through array, you count the number of times you've seen that prefix.
        */
        map<int, int> cnt;
        cnt[0] = 1; // Base case

        int prefix = 0;
        int ans = 0;
        for (int num: nums) {
            prefix += num;
            int need = prefix - k;
            ans += cnt[need];
            cnt[prefix]++;
        }
        return ans;
        
    }
};