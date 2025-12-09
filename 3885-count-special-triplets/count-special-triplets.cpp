class Solution {
public:
    int MOD = int(1e9) + 7;
    int specialTriplets(vector<int>& nums) {
        /*
        */
        unordered_map<int, vector<int>> num_to_pos;
        for (int i = 0;i<nums.size();i++) {
            num_to_pos[nums[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 0;i<nums.size();i++) {
            int target_num = 2 * nums[i];
            const vector<int>& pos = num_to_pos[target_num];

            auto it = upper_bound(pos.begin(), pos.end(), i);

            if (it == pos.begin()) continue; // no number found

            long long n_left = it - pos.begin(); // Number of indices smaller or equal
            long long n_right = pos.end() - it; // number of indices bigger

            if (*(it - 1) == i) n_left--;

            
            ans += (n_left * n_right) % MOD;
            ans %= MOD;
        }
        return ans;
        
    }
};