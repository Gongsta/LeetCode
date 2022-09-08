class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int curr_min = 1 << 30;
        for (int i=0;i<prices.size();i++) {
            max_profit = max(prices[i] - curr_min, max_profit);
            if (prices[i] < curr_min) {
                curr_min = prices[i];
            }
        }
        return max_profit;
        
    }
};