class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        dictionary = {}
        for i in range(len(nums) + 1):
            dictionary[i] = True

        for num in nums:
            dictionary.pop(num)

        for key in dictionary:
            return key
        

        
