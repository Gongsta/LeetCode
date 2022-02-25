class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        total = 0
        average = sum(arr[0:k]) / k
        if (average) >= threshold:
            total += 1
        for i in range(1, len(arr) - k + 1):
            average -= (arr[i-1] / k)
            average += (arr[i+k-1] / k) 
            if (average) >= threshold:
                total += 1

        return total


        
