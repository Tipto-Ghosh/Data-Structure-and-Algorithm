from typing import List
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        # n = len(matrix)
        # dp = [[float('inf')] * n for _ in range(n)]
        # def solve(row , col):
        #     # if we are out of bounds then it's an invalid path
        #     if col < 0 or col >= n:
        #        return float('inf') 
        #     # we reached the target's beyond
        #     if row >= n:
        #         return 0
           
        #     if dp[row][col] != float('inf'):
        #         return dp[row][col]
        #     # 3 way movement
        #     down = solve(row + 1 , col)
        #     right_diagonal = solve(row + 1 , col + 1)
        #     left_diagonal = solve(row + 1 , col - 1)
        #     dp[row][col] = matrix[row][col] + min(down , right_diagonal , left_diagonal)
        #     return dp[row][col]
            
        # we can start from any col of first row
        # ans = float('inf')
        # for col in range(n):
        #     sub_ans = solve(0 , col)
        #     ans = min(ans , sub_ans)
        # return ans
        
        # Solve using Tabulation / bottom-up dp
        n = len(matrix)
        dp = [[0] * n for _ in range(n)]
        # initialize with the last row of the dp array with matrix of last row
        for col in range(n):
            dp[-1][col] = matrix[-1][col]
        
        # now start calculating from the 2nd last row till 0
        for row in range(n - 2 , -1 , -1):
            for col in range(n):
                down = dp[row + 1][col]
                left_diagonal = dp[row + 1][col - 1] if col - 1 >= 0 else float('inf')
                right_diagonal = dp[row + 1][col + 1] if col + 1 < n else float('inf')
                
                dp[row][col] = matrix[row][col] + min(down , left_diagonal , right_diagonal)
        return min(dp[0])
        
        
sol = Solution()
matrix = [[2,1,3],[6,5,4],[7,8,9]]

print(sol.minFallingPathSum(matrix))         