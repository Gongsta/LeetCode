class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long window_size = 1;
        for (int i = 1;i<=prices.size();i++) {
            if (i != prices.size() && prices[i] == prices[i-1] - 1) {
                window_size++;
            } else {
                // Add to answer
                ans += window_size * (window_size + 1) / 2;
                window_size = 1;
            }
        }
        return ans;
        
    }
};