class Solution:
    def myPow(self, x: float, n: int) -> float:
        final = 1
        if n == 0: return 1
        elif n < 0: 
            n = -n
            for i in range(n):
                final *= x
            return 1/final
        else:
            for i in range(n):
                final *= x
            return final

                
        
