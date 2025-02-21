from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # rows , cols = len(grid) , len(grid[0])
        # dp = [[-1] * cols for _ in range(rows)]
        # def solve(row: int , col: int) -> int:
        #     if row >= rows or col >= cols:
        #         return float('inf')
        #     if row == rows - 1 and col == cols - 1:
        #         return grid[row][col]
        #     if dp[row][col] != -1:
        #         return dp[row][col]
            
        #     go_down = solve(row + 1 , col)
        #     go_right = solve(row , col + 1)
        #     dp[row][col] = grid[row][col] + min(go_down , go_right)
        #     return dp[row][col]
        # return solve(0 , 0) 
        # Solve using tabulation
        def tabulation() -> int:
            rows , cols = len(grid) , len(grid[0])
            dp = [[float('inf')] * (cols + 1) for _ in range(rows + 2)] # (rows + 1) x (cols + 1)
                 
        
        
sol = Solution()
grid = [[1,3,1],[1,5,1],[4,2,1]]
grid2 = [[1,2,3],[4,5,6]]
print(sol.minPathSum(grid2))