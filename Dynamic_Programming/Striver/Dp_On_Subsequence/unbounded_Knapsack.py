# class Solution:
#     def knapSack(self, val, wt,capacity):
#         n = len(val)
#         # for every product we have 2 option: Take(if possible) and skip. If take then update capacity and profit
#         dp = [[-1] * (capacity + 1) for _ in range(n)]
#         def solve(index: int , curr_capacity: int) -> int:
#             if index == n or curr_capacity <= 0:
#                 return 0 # No more capacity or items
#             if dp[index][curr_capacity] != -1:
#                 return dp[index][curr_capacity]

#             # Case 01: Skip the current element
#             skip = solve(index + 1 , curr_capacity)
#             # Case 02: Take the item if possible
#             take = 0
#             if curr_capacity >= wt[index]:
#                 take = val[index] + solve(index , curr_capacity - wt[index])
#             dp[index][curr_capacity] = max(take , skip) 
#             return dp[index][curr_capacity]        
#         return solve(0 , capacity)    
            
        # Solve Using Tabulation
        # n = len(val)
        # dp = [[0] * (capacity + 1) for _ in range(n)]
        
        # # take one product from index 0 to n-1
        # for index in range(n):
        #     curr_product = wt[index]
        #     for curr_capacity in range(capacity , )

# sol = Solution()
# val = [1, 1]
# wt = [2, 1]
# capacity = 3
# print(sol.knapSack(val , wt , capacity))

# val = [6, 1, 7, 7]
# wt = [1,3,4,5]

# print(sol.knapSack(val , wt , 8))            



#-------------------------------- Unbounded Knapsack --------------------------
from typing import List

def unboundedKnapsack(n: int, w: int, profit: List[int], weight: List[int]) -> int:
    # dp = [[-1] * (w + 1) for _ in range(n)]
    # def solve_memo(index: int , capacity: int) -> int:
    #     if index == 0:
    #         return profit[0] if weight[0] <= capacity else 0
    #     if dp[index][capacity] != -1:
    #         return dp[index][capacity]
        
    #     skip = solve_memo(index - 1 , capacity)
    #     take = 0
    #     if capacity >= weight[index]:
    #         take = profit[index] + solve_memo(index , capacity - weight[index])
    #     dp[index][capacity] = max(take , skip)
    #     return dp[index][capacity]
    
    # return solve_memo(n - 1 , w)

    dp = [[0] * (w + 1) for _ in range(n)]
    # Base case:
    for capacity in range(w + 1):
        if weight[0] <= capacity:
           # count how many times we can take 0-th item
           count = capacity // weight[0] 
           dp[0][capacity] = count * profit[0] 
    
    # row 0 done now fill the table for 1 to n-1
    for index in range(1 , n):
        for capacity in range(w + 1):
            skip = dp[index - 1][capacity]
            take = 0
            if capacity >= weight[index]:
               take = profit[index] + dp[index][capacity - weight[index]]
            dp[index][capacity] = max(take , skip)             
    return dp[n-1][w]
    
    
    
    
profit = [5, 10, 20]
weight = [7 , 2 , 4]
n = 3
w = 15

print(unboundedKnapsack(n , w , profit , weight))     