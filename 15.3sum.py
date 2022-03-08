class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        for idx, target in enumerate(nums):
            hash_table = {}
            for i in range(idx+1, len(nums)):
                if nums[i] in hash_table:
                    result.append([target, ])

                else:
                    hash_table[]
        
