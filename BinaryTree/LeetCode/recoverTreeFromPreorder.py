from typing import Optional
from collections import defaultdict
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        """
        Intuition of the Approach:
            Parsing the Input String:
            We traverse the string character by character.
            Count dashes (-) to determine the depth of the node.
            Extract the full numerical value of the node.
            Finding the Correct Parent:

            Since this is a preorder traversal, each node appears immediately after its parent in the string.
            If the depth of a node is D, its parent is at depth D-1.
            Using a Stack for Efficient Parent Tracking:

            We maintain a stack where stack[i] represents the last node at depth i.
            When processing a node at depth D:
            Attach it as the left child if its parent has no left child.
            Otherwise, attach it as the right child.
            If stack already has a node at depth D, replace it with the current node.
        """
        
        n = len(traversal)
        index = 0
        stack = [] # to maintain the last node as we start doing DFS
        
        while index < n:
            level = 0
            # count the num of dashes[depth of curr node]
            while index < n and traversal[index] == '-':
                level += 1
                index += 1
            # Now find the node value
            value_start = index
            while index < n and traversal[index].isdigit():
                index += 1
            # find the value sub-string and convert it into int
            node_val = int(traversal[value_start : index])
            # Create the curr node
            node = TreeNode(node_val)
            
            # if node is not a root value then find it's parent and attach it
            if level > 0:
                parent = stack[level - 1] # parent_level = node_level - 1
                
                # If parent dont have any child then first child will be left
                if parent.left is None:
                    parent.left = node
                else: # Other wise it's a right child
                    parent.right = node
            # Maintain the stack for each depth
            if len(stack) > level:
                stack[level] = node
            else:
                stack.append(node)
        
        return stack[0] # cause pre-order traversal so at index 0 the root node is        
        
        