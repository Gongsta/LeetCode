class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """O(n^2) solution
        total = nums[0]
        if len(nums) > 1:
            for i in range(len(nums)):
                other_total = 0
                for j in range(i, len(nums)):
                    other_total += nums[j]
                    total = max(total, other_total)

        return total
        """
        total = nums[0]
        best = nums[0]
        if len(nums) > 1:
            for i in range(1, len(nums)):
                total = max(nums[i], total + nums[i])
                best = max(total, best)
           
        return best
