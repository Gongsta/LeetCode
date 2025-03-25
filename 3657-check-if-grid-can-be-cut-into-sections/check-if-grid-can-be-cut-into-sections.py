import heapq
class Solution:
    def iterate(self,heap):
        intervals = 0
        start, end = heapq.heappop(heap)
        while (len(heap) > 0):
            new_start, new_end = heapq.heappop(heap)
            if (new_start >= end):
                intervals += 1
                start = new_start
                end = new_end
            else:
                end = max(end, new_end)
        return intervals

    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        heap_x = []
        heap_y = []
        for rectangle in rectangles:
            x1,y1,x2,y2 = rectangle
            heapq.heappush(heap_x, (x1,x2))
            heapq.heappush(heap_y, (y1,y2))
        
        # Try along x first
        intervals = self.iterate(heap_x)
        if (intervals >= 2): return True
        intervals = self.iterate(heap_y)
        if (intervals >= 2): return True
        return False

        