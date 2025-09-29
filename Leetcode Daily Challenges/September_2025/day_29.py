from typing import List

class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        dp = [[-1 for _ in range(n)] for _ in range(n)]
        
        def solve(i: int , j: int) -> int:
            # base: if we dont have enough points[less than equal to 2] means i + 1 == j
            if i + 1 == j:
                return 0 # cause no triangle
            
            if dp[i][j] != -1:
                return dp[i][j]
            ans = float("INF")
            # divide the problem in 2 parts like matrix chain multipication
            for k in range(i + 1 , j):
                # form a triangle with i , k , j
                part1 = values[i] * values[k] * values[j]
                # solve i to k
                part2 =  solve(i , k)
                # solve k to j
                part3 = solve(k , j)
                ans = min(ans , part1 + part2 + part3)
            
            dp[i][j] = ans 
            return ans 
        
        return solve(0 , n - 1)
                

sol = Solution()
print(sol.minScoreTriangulation([1,2,3]))
print(sol.minScoreTriangulation([3,7,4,5]))
print(sol.minScoreTriangulation([1,3,1,4,1,5]))