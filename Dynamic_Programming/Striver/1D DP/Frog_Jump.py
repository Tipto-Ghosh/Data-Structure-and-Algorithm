class Solution:
    def minimumEnergy(self, height, n):
    #    dp = [-1] * n # Cause we need till n-1 index
       
    #    def solve(curr_stair: int) -> int:
    #        if curr_stair <= 0: return 0
    #        if dp[curr_stair] != -1:
    #            return dp[curr_stair]
    #        # take one step
    #        one_step = abs(height[curr_stair] - height[curr_stair - 1]) + solve(curr_stair - 1)
    #        # take two step
    #        two_step = float('inf')
    #        if curr_stair - 2 >= 0:
    #            two_step = abs(height[curr_stair] - height[curr_stair - 2]) + solve(curr_stair - 2)
    #        dp[curr_stair] = min(one_step , two_step)
    #        return dp[curr_stair]    
    #    return solve(n - 1)    
    
        # solve using Tabulation
        dp = [0] * n
        # initialize Part
        dp[0] = 0
        dp[1] = abs(height[1] - height[0]) # cost for one step
        for i in range(2 , n):
            # take one step
            one_step = abs(height[i] - height[i-1]) + dp[i-1]
            # take two step
            two_step = abs(height[i] - height[i-2]) + dp[i-2]
            # take the minimum
            dp[i] = min(one_step , two_step)
        return dp[n-1]    
     
     
sol = Solution()
height = [10 , 20 , 30 , 10]
n = 4
print(sol.minimumEnergy(height , n))   