# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        low = 1
        high = n
        while low <= high:
            mid = (low+high) // 2
            if isBadVersion(mid) and (mid == 0 or not isBadVersion(mid - 1)): # Found first bad version
                return mid

            elif isBadVersion(mid):
                high = mid - 1

            elif not isBadVersion(mid):
                low = mid + 1


        
