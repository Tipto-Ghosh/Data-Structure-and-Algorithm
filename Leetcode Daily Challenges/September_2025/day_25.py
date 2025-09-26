from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        Rows = len(triangle)
        dp = {}
        
        def solve(row: int , col: int) -> int:
            if row >= Rows or col < 0 or col >= len(triangle[row]):
                return 0
            
            if (row , col) in dp:
                return dp[(row , col)]    
            
            # we can move to next row and col or col + 1 position
            
            # go to col position
            sum1 = solve(row + 1 , col)
            # go to col + 1 position
            sum2 = solve(row + 1 , col + 1)
            
            dp[(row , col)] = triangle[row][col] + min(sum1 , sum2)
            return dp[(row , col)]
        
        return solve(0 , 0)
    
sol = Solution()
print(sol.minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]))
print(sol.minimumTotal([[-10]]))