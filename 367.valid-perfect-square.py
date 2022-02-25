class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        # We assume 1 <= num <= 2^31 - 1
        left = 0
        right = num
        curr = num // 2

        if num == 1:
            return True
        
        prev_curr = 0

        # Binary search
        while curr != prev_curr:
            if curr ** 2 == num:
                return True

            elif curr ** 2 > num:
                right = curr

            elif curr ** 2 < num:
                left = curr
                
            prev_curr = curr
            curr = (left + right) // 2

        return False

        
