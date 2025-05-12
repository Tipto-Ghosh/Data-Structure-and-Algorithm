from typing import List 

class Solution:
    def findEvenNumbers(self, arr: List[int]) -> List[int]:
        n = len(arr)
        
        Set = set()
        
        for i in range(n):
            if arr[i] == 0:
                continue
            for j in range(n):
                for k in range(n):
                    if i == k or i == j or j == k:
                        continue
                    num = (arr[i] * 100) + (arr[j] * 10) + arr[k]
                    if num % 2 == 0:
                        Set.add(num)
        
        ans = list(Set)
        ans = sorted(ans)
        return ans