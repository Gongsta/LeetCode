class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        """Recursion
        if n == 1: return True
        elif n <= 0 or n % 2 == 1: return False

        return isPowerOfTwo(n/2)
        """

        return n > 0 and (n & (n-1) == 0)
        """Bitwise

        """
        
        """
        Iterative O(logn)
        remainder = n % 2

        if n <= 0: return False

        while n > 1:
            if remainder == 1:
                return False

            n /= 2 # Divide by two
            remainder = n % 2

        return True
        """
        
