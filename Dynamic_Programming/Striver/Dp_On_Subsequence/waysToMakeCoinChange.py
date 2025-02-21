def countWaysToMakeChange(denominations, value) :
    # as we have given an infinity supply of coins so Unbounded Knapsack
    # n = len(denominations)
    # dp = [[-1] * (value + 1) for _ in range(n)]
    # def solve(index: int , amount: int) -> int:
    #     # Base Case:
    #     if index == 0:
    #         return 1 if amount % denominations[index] == 0 else 0
    #     if dp[index][amount] != -1:
    #         return dp[index][amount]
    #     dont_take = solve(index - 1 , amount)
    #     take = 0
    #     if amount >= denominations[index]:
    #         take = solve(index , amount - denominations[index])
    #     # asking for total number of ways
    #     dp[index][amount] = take + dont_take
    #     return dp[index][amount]
    
    # return solve(n - 1 , value)     
    
    n = len(denominations)
    dp = [[0] * (value + 1) for _ in range(n)]
    # Base Case: for row 1 if amount(0 to value) amount % denominations[index] == 0 then 1
    for amount in range(value + 1):
        if amount % denominations[0] == 0:
           dp[0][amount] = 1 
    # We are done with index 0 now from 1 to n-1
    for index in range(1 , n):
        for amount in range(value + 1):
            dont_take = dp[index - 1][amount]
            take = 0
            if amount >= denominations[index]:
               take = dp[index][amount - denominations[index]]
            # asking for total number of ways
            dp[index][amount] = take + dont_take
    # row end at n-1 and col end at amount
    return dp[n-1][amount]
arr = [1,2,3]
print(countWaysToMakeChange(arr , 4))