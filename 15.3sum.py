class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        final = []
        for idx, val in enumerate(nums[:-2]):
            hash_table = {}
            for idx2, val2 in enumerate(nums[idx+1:]):
                if val - val2 in hash_table:
                    final.append([val, val2, val-val2])

                else: 
                    hash_table[val2] = True

        return final
        
