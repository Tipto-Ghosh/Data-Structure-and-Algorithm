from typing import List
from collections import defaultdict

class Solution:
    def minimumOperations(self, arr: List[int]) -> int:
        seen = set()
        n = len(arr)
        
        index = -1
        
        for i in range(n-1 , -1 , -1):
            if arr[i] not in seen:
                seen.add(arr[i])
            else:
                index = i 
                break
        
        # remove all till index
        count_op = 0
        
        i = 0
        while i <= index:
            i += 3
            count_op += 1
        
        return count_op                         
        
        
        
        
sol = Solution()
print(sol.minimumOperations([1,2,3,4,2,3,3,5,7]))
print(sol.minimumOperations([4,5,6,4,4]))
print(sol.minimumOperations([6,7,8,9]))        