
"""

total_islands = 0
visitd = set()
Iterate over the matrix:
    do BFS if it hasn't been visited yet
"""
from collections import deque
class Solution:
    def __init__(self):
        self.visited = set() # Set of (i,j) tuples
        self.directions = [[1,0], [0,1], [-1, 0], [0, -1]]

    def in_bounds(self,i, j, grid):
        return i >= 0 and j >= 0 and i < len(grid) and j < len(grid[0])

    def numIslands(self, grid: List[List[str]]) -> int:
        total_islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if ((i,j) not in self.visited) and grid[i][j] == '1':
                    total_islands += 1
                    self.bfs(i,j, grid)
        
        return total_islands
    
    def bfs(self, start_i, start_j, grid):
        queue = deque()
        self.visited.add((start_i,start_j))
        queue.append((start_i,start_j))
        while len(queue) > 0:
            i,j = queue[0]
            queue.popleft()
            for increment_i, increment_j in self.directions:
                next_i = i + increment_i
                next_j = j + increment_j
                if (self.in_bounds(next_i, next_j, grid)
                    and ((next_i, next_j) not in self.visited) 
                    and grid[next_i][next_j] == '1'):
                    self.visited.add((next_i, next_j))
                    queue.append((next_i, next_j))




        