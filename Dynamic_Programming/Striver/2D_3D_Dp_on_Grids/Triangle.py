from typing import List
from collections import defaultdict
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # rows = len(triangle)
        # # so at every level(row) i have 2 option either go straight down or col + 1 down
        # # we have 2 changing property row and col
        # # we hashmap cause array col is variable length
        # dp = defaultdict(int)
        # def solve(level: int , col: int) -> int:
        #     if level >= rows:
        #         return 0           
        #     # if col is out of bounds no valid answer
        #     if  col >= len(triangle[level]):
        #         return float('inf')
        #     if (level , col) in dp:
        #         return dp[(level , col)]
        #     # go down to the same col
        #     option1 = solve(level + 1 , col)
        #     # go down but at adjacency col
        #     option2 = solve(level + 1 , col + 1)
        #     ans = triangle[level][col] + min(option1 , option2)
        #     dp[(level , col)] = ans
        #     return ans
        
        # ans = solve(0 , 0)
        # print(dp)        
        # return ans
        def tabulation() -> int:
            total_levels = len(triangle)
            dp = triangle[-1][:] # initialize with the last row
            # for each row try to go straight up or 1 step left then up
            for row in range(total_levels - 2 , -1 , -1):
                for col in range(len(triangle[row])):
                    dp[col] = triangle[row][col] + min(dp[col] , dp[col + 1])
            return dp[0]        
            
        return tabulation()
sol = Solution()
triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
print(sol.minimumTotal(triangle))    