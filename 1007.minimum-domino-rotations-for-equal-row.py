class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        swaps = 0
        first_four = tops[:2] + bottoms[:2]

        # We case two cases: 1 rotation and 2 rotations
        for i in range(len(tops)):
        
        
