class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # i need a grid first [M x N]
        # 2 changing property row and col
        # 2 way movements: down and right
        dp = [[-1] * n for _ in range(m)]
        
        def solve(row: int , col: int) -> int:
            # if we are at target position we get a valid path
            if row == m - 1 and col == n - 1:
                return 1
            # if we are out-of-bounds then no valid path
            # always right or down to there is no chance to get -ve index
            if row >= m or col >= n:
                return 0
            if dp[row][col] != -1:
                return dp[row][col]
            # we have two choice 
            go_down = solve(row + 1 , col)
            go_right = solve(row , col + 1)
            # need to find all the unique path so sum up these 2
            dp[row][col] = go_down + go_right
            return dp[row][col]
        ans = solve(0 , 0)
        # print(dp)
        return ans    
            
sol = Solution()
print(sol.uniquePaths(3 , 2))            