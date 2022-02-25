class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        min_price, max_profit = float('inf'), 0
        for price in prices:
            min_price = min(min_price, price)
            profit = price - min_price
            max_profit = max(profit, max_profit)


        if max_profit <= 0:
            return 0
        else:
            return max_profit

