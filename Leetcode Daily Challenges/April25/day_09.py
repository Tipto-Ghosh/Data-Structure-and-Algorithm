from typing import List


class Solution:
    def minOperations(self, arr: List[int], k: int) -> int:
        minEle = min(arr)
        Set = set(arr)
        count = len(Set)
        
        if k > minEle:
            return -1
        elif minEle == k:
            return len(Set) - 1
        else:
            return len(Set) 
        
        
sol = Solution()

print(sol.minOperations([5,2,5,4,5], k = 2))
print(sol.minOperations([2,1,2], k = 2))
print(sol.minOperations([9,7,5,3], k = 1))        