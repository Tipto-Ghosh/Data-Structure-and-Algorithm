class Solution:
    mod = int(10e9 + 7)
    def topDown(self, n):
        # top down we start with the big(main) problem and divide in sub-problem
        dp = [-1] * (n + 1) 
        def solve(num: int) -> int:
            if num == 0:
                return 0
            if num == 1:
                return 1
            if dp[num] != -1:
                return dp[num]
            
            dp[num] = ((solve(num - 1) % Solution.mod) + (solve(num - 2) % Solution.mod)) % Solution.mod
            return dp[num]
        return solve(n)
    def bottomUp(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        dp = [0] * (n + 1)
        dp[1] = 1
        for i in range(2 , n + 1):
            dp[i] = ((dp[i-1] % Solution.mod) + (dp[i-2] % Solution.mod)) % Solution.mod
        return dp[n]    
    
sol = Solution()
print(sol.bottomUp(5))
print(sol.topDown(5))  
print(sol.mod)  