from typing import List
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        seen = set()
        ans = []
        for r in range(n):
            for c in range(n):
                if grid[r][c] in seen:
                   ans.append(grid[r][c])
                else:
                    seen.add(grid[r][c])
        for num in range(1 , n * n + 1):
            if num not in seen:
                ans.append(num)
                break
        
        return ans

     
        