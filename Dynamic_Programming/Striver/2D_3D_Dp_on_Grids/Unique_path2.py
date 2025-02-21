from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        ROWS , COLS = len(obstacleGrid) , len(obstacleGrid[0])
        dp = [[-1] * COLS for _ in range(ROWS)]
        def solve(row: int , col: int) -> int:
            # if there is an obstacle we also can't move
            if row >= ROWS or col >= COLS or obstacleGrid[row][col] == 1:
                return 0
            if row == ROWS - 1 and col == COLS - 1:
                return 1
            if dp[row][col] != -1:
                return dp[row][col]
            go_down = solve(row + 1 , col)
            go_right = solve(row , col + 1)
            dp[row][col] = go_down + go_right
            return dp[row][col]
        ans = solve(0 , 0)
        # print(dp)
        return ans

sol = Solution()
obstacleGrid = [[0,1],[0,0]]
print(sol.uniquePathsWithObstacles(obstacleGrid))            