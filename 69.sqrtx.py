class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        left = 1
        right = x // 2 + 1


        # Use binary search
        while left <= right:
            mid = (left + right) // 2

            if mid**2 == x:
                return mid

            elif mid**2 < x:
                left = mid + 1

            elif mid**2 > x:
                right = mid - 1

        if mid ** 2 > x:
            return mid - 1
        else:
            return mid

        
