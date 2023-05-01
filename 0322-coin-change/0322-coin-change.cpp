class Solution {
public:
    bool solved[10001];
    int dp[10001];
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (solved[amount]) {
            return dp[amount];
        }
        int min_coins = 1e9;
        for (int coin: coins) {
            if (amount - coin < 0) continue;
            int coins_needed = coinChange(coins, amount-coin);
            if (coins_needed != -1) {
                min_coins = min(min_coins, coins_needed + 1);
            }
        }
        if (min_coins != 1e9) {
            dp[amount] = min_coins;
        } else {
            dp[amount] = -1;
        }
        solved[amount] = true;
        return dp[amount];
    }
};