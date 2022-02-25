class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        hash_table = {}
        for l in s:
            if l in hash_table:
                hash_table[l] += 1
            else:
                hash_table[l] = 1

        for l in t:
            if l in hash_table:
                hash_table[l] -= 1
            else:
                return l

        for key in hash_table:
            if hash_table[key] != 0:
                return key
        
