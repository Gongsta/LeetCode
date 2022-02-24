"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:

    def cloneGraph(self, node: 'Node') -> 'Node':
        if node:
            head_node = Node(node.val)
            head_node.neighbors = list()

            stack = list()
            for neighbor in node.neighbors:
                stack.append(neighbor)

            while not stack.isEmpty():
                neighbor = stack.pop()
                neighbor_copy = Node(neighbor.val)
                for sub_neighbors in neighbor.neighbors:
                    stack.append(sub_neighbor)
            
            return head_node

        else:
            return None
        
