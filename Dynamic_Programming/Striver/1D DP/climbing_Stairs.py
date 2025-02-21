class Solution:
    def climbStairs(self, n: int) -> int:
        # dp = [-1] * (n + 1)
        
        # def solve(curr_stair: int) -> int:
        #     if curr_stair <= 0: return 0
        #     if curr_stair == 1 or curr_stair == 2:
        #         return curr_stair
        #     if dp[curr_stair] != -1: return dp[curr_stair]
            
        #     # take 1 step
        #     one_step = solve(curr_stair - 1)
        #     # take 2 step
        #     two_step = solve(curr_stair - 2)
        #     # total ways
        #     dp[curr_stair] = one_step + two_step
        #     return dp[curr_stair]
        # return solve(n)
        
        # using Tabulation method[Buttom-Up Method]
        # dp = [0] * (n + 1)
        # dp[1] = 1
        # dp[2] = 2
        # for i in range(3 , n + 1):
        #     dp[i] = dp[i - 1] + dp[i - 2]
        # return dp[n]    
        
        # Space optimized
        if n <= 2:
            return n
        prev1 , prev2 = 1 , 2
        for i in range(3 , n + 1):
            curr = prev1 + prev2
            prev1 , prev2 = prev2 , curr
        return prev2
sol = Solution()
print(sol.climbStairs(23))
print(sol.climbStairs(3))    