class Solution:
    def rob(self, nums: List[int]) -> int:
        total1 = 0
        total2 = 0
        
        for i in range(len(nums)):
            if i % 2 == 0:
                total1 += nums[i]
            else:
                total2 += nums[i]
                 
        return max(total1, total2)
        
