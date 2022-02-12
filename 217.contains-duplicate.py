class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_dict = {}
        for val in nums:
            if val in num_dict:
                return True
            else:
                num_dict[val] = True
        
        return False
        
