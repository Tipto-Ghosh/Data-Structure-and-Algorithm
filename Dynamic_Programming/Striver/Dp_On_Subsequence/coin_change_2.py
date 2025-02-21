from typing import List
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # n = len(coins)
        # dp = [[-1] * (amount + 1) for _ in range(n)]
        # def solve(curr_amount: int , index: int) -> int:
        #     if curr_amount == 0:
        #         return 1
        #     if curr_amount < 0:
        #         return 0
        #     if dp[index][curr_amount] != -1:
        #         return dp[index][curr_amount] 
        #     res = 0
        #     # try to take every coins and find the ways
        #     for i in range(index , n):
        #         if curr_amount >= coins[i]:
        #             sub_ans = solve(curr_amount - coins[i] , i)
        #             res += sub_ans 
        #     dp[index][curr_amount] = res
        #     return res
        # return solve(amount , 0)
        
        # Solve Using Tabulation
        n = len(coins)
        dp = [[0] * (amount + 1) for _ in range(n)]
        
        # Base Case: in the every row for every coins if amount is 0 then ways will be 0[No coin peak]
        for i in range(n):
            dp[i][0] = 1
        
        # Now start fiiling the dp table
        for index in range(n):
            # Try to find the number of ways to make the amount with this current coin
            for a in range(1 , amount + 1):
                # take the coin if possible
                if a >= coins[index]:
                    dp[index][a] += dp[index][a - coins[index]] 
                # add ways without using the current coin
                if index - 1 >= 0:
                  dp[index][a] += dp[index - 1][a]
        # now at last row and amount-th col will be the answer
        return dp[n-1][amount]               
 
 
 
# sol = Solution()
# coins1 = [1,2,5]
# coins2 = [2]
# coins3 = [10]

# print(sol.change(5 , coins1))
# print(sol.change(3 , coins2))
# print(sol.change(10 , coins3))        

n = int(input("Enter size: "))
arr = [int(x) for x in input("Enter elements: ").split()[ : n]]
print(arr)