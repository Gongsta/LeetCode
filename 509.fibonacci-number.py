class Solution:
    def fib(self, n: int) -> int:
        prev_1 = 1
        prev_2 = 0

        for i in range(n):
            prev_1, prev_2 = prev_1+prev_2, prev_1

        return prev_2

        
