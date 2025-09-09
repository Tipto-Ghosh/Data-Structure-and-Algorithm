class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD = 10**9 + 7
        
        dp = [0] * (n + 1)
        dp[1] = 1 # at day 1 , knows only 1 person
        
        # now find from day 2 to  n
        for day in range(2 , n + 1):
            # people who share on this day
            for prev in range(max(1 , day - forget + 1) , day - delay + 1):
                dp[day] = (dp[day] + dp[prev]) % MOD
        
        ans = sum(dp[max(1 , n - forget + 1) : n + 1]) % MOD 
        return ans 


print(Solution().peopleAwareOfSecret(6, 2, 4))    