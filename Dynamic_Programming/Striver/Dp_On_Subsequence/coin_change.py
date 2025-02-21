from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # n = len(coins)
        # dp = [-1] * (amount + 1)
        # def solve(curr_amount: int) -> int:
        #     if curr_amount == 0:
        #         return 0
        #     if curr_amount < 0:
        #         return float('inf')
        #     if dp[amount] != -1:
        #         return dp[amount]
            
        #     ans = float('inf')
        #     for i in range(n):
        #         take = solve(curr_amount - coins[i])
        #         if take != float('inf'):
        #             ans = min(ans , 1 + take)
        #     dp[curr_amount] = ans
        #     return ans
        # ans = solve(amount)
        # print(dp)
        # return ans if ans != float('inf') else -1
    
        # --------------- Tabulation ---------------------
        # step-1: initialize dp table
        dp = [float('inf')] * (amount + 1)
        # base case
        dp[0] = 0 # when amount 0 we need 0 coins
        for curr_amount in range(1 , amount + 1):
            for coin in coins:
                if curr_amount >= coin:
                  dp[curr_amount] = min(dp[curr_amount] , 1 + dp[curr_amount - coin])
        return -1 if dp[amount] == float('inf') else dp[amount]        





sol = Solution()
arr1 = [1,2,5]
arr2 = [2]
arr3 = [1]

print(sol.coinChange(arr1 , 11))        