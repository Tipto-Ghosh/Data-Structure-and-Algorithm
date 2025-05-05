class Solution:
    def numTilings(self, n: int) -> int:
        mod = (10**9) + 7
        
        dp = [-1 for _ in range(n + 1)]
        
        def solve(val: int) -> int:
            if val == 1 or val == 2:
                return val 
            
            if val == 3:
                return 5
            
            if dp[val] != -1:
                return dp[val]
            
            dp[val] = ((2 * solve(val - 1)) % mod) + ((solve(val - 3)) % mod)
            dp[val] = dp[val] % mod 
            
            return dp[val]
        
        return solve(n)
    
    
sol = Solution()

print(sol.numTilings(5)) 