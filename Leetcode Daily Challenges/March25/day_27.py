from typing import Counter, List
from collections import defaultdict
class Solution:
    def minimumIndex(self, arr: List[int]) -> int:
        # for each part maintain 2 thing
        # 1. Count of elements
        # 2. Set of dominants
        
        # Assume we split at n-1[max possible] index so every element is a part of second split
        first_half = defaultdict(int)
        second_half = defaultdict(int)
        for ele in arr:
            second_half[ele] += 1
            
        n = len(arr)
        
        for i in range(n):
            # Let's split at i-th index
            # So arr[i] is part of first half
            num = arr[i]
            first_half[num] += 1
            # So if arr[i] is a part of first half then it can't be a part of seconf half
            second_half[num] -= 1
            
            if (first_half[num] * 2 > i + 1) and (second_half[num] * 2 > n - i - 1):
                return i 
        
        return -1
        
        
        
        
sol = Solution()

print(sol.minimumIndex([1,2,2,2]))
print(sol.minimumIndex([2,1,3,1,1,1,7,1,2,1]))
print(sol.minimumIndex([3,3,3,3,7,2,2]))   
print(sol.minimumIndex([1,1,1,2]))             