class Solution {
public:
    int MOD = int(1e9) + 7;
    int specialTriplets(vector<int>& nums) {
        /*
        */
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        for (int i = 0;i<nums.size();i++) {
            right[nums[i]]++;
        }

        int ans = 0;
        for (int i = 0;i<nums.size();i++) {
            // Decrement right side cnt
            right[nums[i]]--;

            int target_num = 2 * nums[i];
            long long n_left = left[target_num];
            long long n_right = right[target_num];

            ans += (n_left * n_right) % MOD;
            ans %= MOD;
            
            //Increment left side cnt
            left[nums[i]]++;
        }
        return ans;
        
    }
};