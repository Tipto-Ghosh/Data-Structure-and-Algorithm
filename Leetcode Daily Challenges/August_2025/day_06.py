from typing import List


class SegmentTree:
    def __init__(self , data):
        self.n = len(data)
        
        # Allocate enough space(4n)
        self.size = 4 * self.n
        self.tree = [0] * self.size # segment tree array
        
        # build the tree
        self._build(data , 1 , 0 , self.n - 1)
    
    
    def _build(self , data , node , left , right):
        # recursive function to build the tree
        if left == right:
            # leaf node, store the actual data
            self.tree[node] = data[left] # or data[right]
            return
        
        # find the mid
        mid = (left + right) // 2
        
        # left child range will be left to mid
        self._build(data , 2 * node , left , mid)
        # right child range will be mid + 1 to right
        self._build(data , 2 * node + 1 , mid + 1 , right)
        
        # node value will be max of left and right here
        self.tree[node] = max(self.tree[2 * node] , self.tree[2 * node + 1])
    
    
    def _update(self , node , left , right , index , value):
        # Recursive point update: update index `index` to new `value`
        if left == right:
            self.tree[node] = value 
            return
        
        mid = (left + right) // 2
        
        if index <= mid: # go left
            self._update(2 * node , left , mid , index , value)
        else: # go right
            self._update(2 * node + 1 , mid + 1 , right , index , value)
        
        self.tree[node] = max(self.tree[2 * node] , self.tree[2 * node + 1])
    
    def update(self , index , value):
        # public update method
        self._update(1 , 0 , self.n - 1 , index , value) 
    
    def _query(self , node , left , right , query_left , query_right):
        # Range max query: find max in range [query_left, query_right]
        if query_left > right or query_right < left: # out of range
            return float('-INF')
        
        if query_left <= left and right <= query_right: # Fully in range
            return self.tree[node]
        
        mid = (left + right) // 2
        left = self._query(2 * node , left , mid , query_left , query_right)
        right = self._query(2 * node + 1 , mid + 1 , right , query_left , query_right)
        
        return max(left , right)
    
    def query(self , query_left , query_right):
        return self._query(1 , 0 , self.n - 1 , query_left , query_right)
    
    def find_first_index(self , node , left , right , x):
        # Find the first index in [left, right] with value >= x
        if self.tree[node] < x:
            return -1  # No such value in this subtree
        if left == right:
            return left   # Found at a leaf
        
        mid = (left + right) // 2
        
        # Search in the left subtree first
        left = self.find_first_index(2 * node, left, mid, x)
        
        if left != -1:
            return left
        
        # If not found in left, try right subtree
        return self.find_first_index(2 * node + 1, mid + 1, right, x)  
        
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(baskets)
        
        if n == 0:
           return len(fruits)
        
        # Initialize the segment tree with basket capacities
        tree = SegmentTree(baskets)
        unplaced = 0 # Count of fruits that could not be placed
        
        # Try placing each fruit
        for fruit in fruits:
            # Find the first basket with capacity >= fruit
            idx = tree.find_first_index(1, 0, n - 1, fruit)
            
            if idx == -1:
                # No valid basket found
                unplaced += 1
            else:
                # Basket found; mark it as used by setting value to -1
                tree.update(idx, -1)

        return unplaced  
        
        
        
sol = Solution()

print(sol.numOfUnplacedFruits(fruits = [4,2,5], baskets = [3,5,4]))
print(sol.numOfUnplacedFruits(fruits = [3,6,1], baskets = [6,4,7]))