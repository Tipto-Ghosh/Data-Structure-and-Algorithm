class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = 10 ** 9 + 7
        
        max_base = 1
        
        while (max_base + 1) ** x <= n:
            max_base += 1
        
        dp = [[-1] * (n + 1) for _ in range(max_base + 2)]
        
        def solve(curr_base , curr_n):
            # if curr_n is equal to 0 then we just get a new way
            if curr_n == 0:
                return 1
            if curr_n < 0 or curr_base > max_base: # we exceed
                return 0
            
            if dp[curr_base][curr_n] != -1:
                return dp[curr_base][curr_n]
            
            # skip current base
            not_take = solve(curr_base + 1 , curr_n)
            # take current base
            take = solve(curr_base + 1 , curr_n - curr_base ** x)
            
            dp[curr_base][curr_n] = (take + not_take) % mod 
            return dp[curr_base][curr_n]
         
        return solve(1 , n)
            

sol = Solution()

print(sol.numberOfWays(10 , 2))
print(sol.numberOfWays(4 , 1))
print(sol.numberOfWays(64 , 3))