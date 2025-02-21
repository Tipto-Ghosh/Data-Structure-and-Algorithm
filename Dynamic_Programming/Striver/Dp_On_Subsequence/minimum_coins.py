from typing import List
# Coin Change Greedy works when fixed coins just amount is changing
# When amount and coin both are changing we need DP
def minimumElements(num: List[int], x: int) -> int:
    # n = len(num)
    # dp = [[-1] * (x + 1) for _ in range(n)]
    # def solve(index: int , target: int) -> int:
    #     # Base Case:
    #     # If We are out of coins[index]
    #     if index == 0:
    #         # check is possible to get target
    #         if target % num[index] == 0: # we can achieve
    #            return target // num[index] 
    #         else:
    #             return float('inf') 
        
    #     if dp[index][target] != -1:
    #         return dp[index][target]    
        
    #     # We have 2 Case: Take and Don't take
    #     dont_take = 0 + solve(index - 1 , target)
    #     take = float('inf')
    #     # Check can we take the coin?
    #     if target >= num[index]:
    #         take = solve(index , target - num[index])
    #         if take != float('inf'):
    #             take += 1
    #     dp[index][target] = min(take , dont_take)
    #     return dp[index][target]
    # ans = solve(n - 1 , x)
    # # if ans == ing --means we can't make the target  
    # return -1 if ans == float('inf') else ans
    
    # ----------------- Solve Using Tabulation -------------------
    def tabulation() -> int:
        n = len(num)
        dp = [[0] * (x + 1) for _ in range(n)]
        # Base Case: 
        for target in range(x + 1):
            dp[0][target] = target // num[0] if target % num[0] == 0 else float('inf')
        
        # row 0 is done. Changing parameter 2 so nested loop. Row is index col is target 
        # So index outer loop and target inner loop
        for index in range(1 , n):
            for target in range(x + 1):
                # We have 2 Case: Take and Don't take
                dont_take = 0 + dp[index - 1][target]
                take = float('inf')
                # Check can we take the coin?
                if target >= num[index]:
                    take = dp[index][target - num[index]]
                    if take != float('inf'):
                      take += 1
                dp[index][target] = min(take , dont_take)    
        # Think Where is the final ans: At the end
        # End: Row_end: n-1 , col_end: target , target means x
        return dp[n-1][x]             
    ans = tabulation()
    return -1 if ans == float('inf') else ans    


        
arr = [5 , 3 , 2]
print(minimumElements(arr , 1))     