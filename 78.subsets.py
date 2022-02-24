class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        final = []
        final.append([])
        for start in range(len(nums)):
            for stop in range(start, len(nums)):
                if start == stop:
                    final.append([nums[start]])
                elif stop - start == 1:
                    final.append(nums[start:stop+1])
                else: # Gap > 2, we need to account for extra possibilities
                    for i in range(1,stop-start+1):
                        if i % 2 == 0:
                            final.append(nums[start:stop+1:i])
                        else:


        return final

            
        
