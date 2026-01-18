class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // 1 3 5
        long long ans = 0;
        vector<pair<long long, long long>> min_st;
        vector<pair<long long, long long>> max_st;
        min_st.push_back({INT_MIN, -1});
        max_st.push_back({INT_MAX, -1});

        for (int i = 0;i<=nums.size();i++) {
            int min_num = i == nums.size() ? INT_MIN : nums[i];
            int max_num = i == nums.size() ? INT_MAX : nums[i];

            while (!min_st.empty() && min_num < min_st.back().first) {
                auto [prev, idx] = min_st.back();
                min_st.pop_back();
                ans -= prev *(i - idx) * (idx - min_st.back().second);
            }

            while (!max_st.empty() && max_num > max_st.back().first) {
                auto [prev, idx] = max_st.back();
                max_st.pop_back();
                ans += prev * (i - idx) * (idx - max_st.back().second);
            }

            min_st.push_back({min_num, i});
            max_st.push_back({max_num, i});
        }

        return ans;
    }
};