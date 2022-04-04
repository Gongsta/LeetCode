class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        negative = False
        final = 0
        if dividend < 0:
            negative = not negative
            dividend = -dividend

        if divisor < 0:
            negative = not negative
            divisor = -divisor

        while dividend > 0:
            dividend -= divisor
            final += 1


        if negative:
            final = -final

        if dividend == 0:
            return final

        elif negative:
            final += 1
        else:
            final -= 1

        return final

            
            

        
