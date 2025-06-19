from typing import List
from collections import defaultdict

class Solution:
    def partitionArray(self, arr: List[int], k: int) -> int:
        arr.sort()
        
        # print(arr)
        
        count = 1 # let's say all element can be fitted in one single sequence
        left = 0
        
        for right in range(len(arr)):
            if arr[right] - arr[left] > k:
               count += 1 # violate the rule so add a new sequence
               left = right 
        
        return count 
                
                

sol = Solution()

print(sol.partitionArray([3,6,1,2,5], k = 2))
print(sol.partitionArray([1,2,3], k = 1))
print(sol.partitionArray([2,2,4,5], k = 0))