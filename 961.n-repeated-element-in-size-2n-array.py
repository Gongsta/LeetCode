class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        hash_table = {}
        for i in nums:
            if i in hash_table:
                return i
            else:
                hash_table[i] = True
        
        return -1
        
