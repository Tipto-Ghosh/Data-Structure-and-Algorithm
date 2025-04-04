# Definition for a binary tree node.
from typing import List , Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Brute Force
        # Find the path from root to p and root to q
        # Then take the last common node that is common in both of them
        """
        def find_path(node: 'TreeNode' , target: 'TreeNode' , path: List) -> bool:
            # if we are at None
            if node is None:
               return False  
            # if we are at the target node then take it and say we got it
            if node.val == target.val:
                path.append(target)
                return True
            
            # Take the node in path
            path.append(node)
            # Go to left to find the target node
            left = find_path(node.left , target , path)
            # if we got target from the left then we are done, return. No need to search in right
            if left:
                return True
            # otherwise go to right to find the path
            right = find_path(node.right , target , path)
            if right:
                return True
            
            # If we didn't find the expected target, that mean's curr node is not a part of the target node's path
            path.pop()
            return False
        
        p_path = []
        find_path(root , p , p_path)
        q_path = []
        find_path(root , q , q_path)
        
        # Now find the deepest common node
        i = 0
        lca = root
        
        while i < len(p_path) and i < len(q_path):
            # if common node in both path then take it and go deep
            if  p_path[i].val == q_path[i].val:
                lca = p_path[i]
                i += 1
            else: # No common so break
                break
        
        return lca 
        """
        
        # Now more optimized way
        
        def solve(node: TreeNode , target1: TreeNode , target2: TreeNode) -> TreeNode:
            # If we are at None
            if node is None:
                return node
            
            # If we got one of our target
            if node.val == target1.val or node.val == target2.val:
                return node 
            
            # check to the left side
            left_part = solve(node.left , target1 , target2)
            # check to the right side
            right_part = solve(node.right , target1 , target2)
            
            # if both return non-None value the means node is the lca
            if left_part and right_part:
                return node 
            # other wise we found any of them or none
            # if both none return none , if one of them non-none return return
            return left_part if left_part else right_part
        
        return solve(root , p , q)