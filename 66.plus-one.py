class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        idx = len(digits) - 1
        while digits[idx] + 1 == 10:
            digits[idx] = 0
            idx -= 1
            if idx == -1:
                break

        if idx == -1: # We need to resize the array and insert at index 0
            digits.insert(0, 1)

        else:
            digits[idx] += 1

        return digits
        
