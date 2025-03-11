from typing import Optional
from collections import deque
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.all_root_values = set()
        # root.val = 0 [that is always fixed]
        # if root.left != None then root.left.val = 2 * root.val + 1
        # if root.right != None then root.right.val = 2 * root.val + 2
        
        # apply bfs and find all the root values        
        if self.root:
            self.root.val = 0
            self.all_root_values.add(0)
            q = deque([self.root])
            
            while q:
                curr_node = q.popleft()
                
                # Go for left child
                if curr_node.left:
                    curr_node.left.val = 2 * curr_node.val + 1
                    self.all_root_values.add(curr_node.left.val)
                    q.append(curr_node.left)
                # Go for right child
                if curr_node.right:
                    curr_node.right.val = 2 * curr_node.val + 2
                    self.all_root_values.add(curr_node.right.val)    
                    q.append(curr_node.right)    
            

    def find(self, target: int) -> bool:
        return target in self.all_root_values 