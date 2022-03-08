class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = 0 
        high = len(nums) - 1
        
        if target < nums[0]:
            return 0

        elif target > nums[-1]:
            return len(nums)

        while low <= high:
            mid = (low + high) // 2

            if nums[mid] == target or (nums[mid] > target and nums[mid-1] < target):
                return mid

            elif nums[mid] < target:
                low = mid + 1

            elif nums[mid] > target:
                high = mid - 1

        
