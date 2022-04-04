class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        """
        Different Ways to solve this problem:
        1. Recursively calling rotate right by 1
        2. Storing a copy of subarray, and then "pasting" it later
        3. for loop that keeps rotating by one
        4. Using pointers

        """
        
        
