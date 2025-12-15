class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        long long window_size = 1;
        for (int i = 1;i<prices.size();i++) {
            if (i != prices.size() && prices[i] == prices[i-1] - 1) {
                window_size++;
            } else {
                window_size = 1;
            }
            ans += window_size;
        }
        return ans;
        
    }
};