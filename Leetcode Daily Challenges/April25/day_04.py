# Definition for a binary tree node.
from typing import List , Optional
from collections import defaultdict , deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(values: List[Optional[int]]) -> Optional[TreeNode]:
    if not values or values[0] is None:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    index = 1

    while queue and index < len(values):
        node = queue.popleft()

        # Left child
        if index < len(values) and values[index] is not None:
            node.left = TreeNode(values[index])
            queue.append(node.left)
        index += 1

        # Right child
        if index < len(values) and values[index] is not None:
            node.right = TreeNode(values[index])
            queue.append(node.right)
        index += 1

    return root        


class Solution(object):
    def lcaDeepestLeaves(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        def dfs(node, depth):
            if not node:
                # If node is None, return (None, current depth)
                return (None, depth)
            
            # Recursively traverse left and right children
            left_lca, left_depth = dfs(node.left, depth + 1)
            right_lca, right_depth = dfs(node.right, depth + 1)

            if left_depth > right_depth:
                # Left subtree is deeper → propagate its LCA and depth upward
                return (left_lca, left_depth)
            elif right_depth > left_depth:
                # Right subtree is deeper → propagate its LCA and depth upward
                return (right_lca, right_depth)
            else:
                # Both subtrees are at the same depth → current node is LCA
                return (node, left_depth)

        # Start recursive DFS from the root at depth 0
        lca_node, _ = dfs(root, 0)
        return lca_node