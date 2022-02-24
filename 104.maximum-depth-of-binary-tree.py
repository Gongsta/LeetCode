# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        else:
            max_depth = 1
            curr_depth = 1

            frontier = []
            if root.left:
                frontier.append(root.left)
            
            if root.right:
                frontier.append(root.right)

            # Use DFS to find a max_depth
            while len(frontier) > 0:
                node = frontier.pop()
                curr_depth += 1

                if node.left:
                    frontier.append(node.left)

                if node.right:
                    frontier.append(node.right)

                if not node.right and not node.left: # update the max_depth when we have reached a dead end
                    if curr_depth > max_depth:
                        max_depth = curr_depth

                    curr_depth -= 1 # Going back up a node
                    frontier.pop()

            
            return max_depth





        
        
