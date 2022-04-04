from collections import deque
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1
        
        final = deque()

        while left <= right:
            if abs(nums[left]) > abs(nums[right]):
                final.appendleft(nums[left] ** 2)
                left += 1 
            else:
                final.appendleft(nums[right] ** 2)
                right -= 1

        return final

        
