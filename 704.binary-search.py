class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0 
        right = len(nums) - 1
        curr = right // 2

        while left <= right:
            if nums[curr] > target:
                right = curr - 1
            elif nums[curr] < target:
                left = curr + 1

            else:
                return curr

            curr = (left + right) // 2

        return -1
        
