from typing import List
from collections import defaultdict
class Solution:
    def findTargetSumWays(self, arr: List[int], target: int) -> int:
        n = len(arr)
        dp = defaultdict(int)
        def solve(index: int , curr_value: int) -> int:
            # base case: if we reched end we have no more element so check result
            if index == n:
                return 1 if curr_value == target else 0
            if (index , curr_value) in dp:
                return dp[(index , curr_value)]
            # for every element we have 2 options: add '+' or '-'
            addition = solve(index + 1 , curr_value + arr[index])
            substraction = solve(index + 1 , curr_value - arr[index])
            dp[(index , curr_value)] = addition + substraction
            return dp[(index , curr_value)]
        
        # return solve(0 , 0)
        # ------------- Solve Using Tabulation---------------------
        # there is 2 state variable: index and curr_value so 2D DP table
        # the curr_value range is -total to +total
        n = len(arr)
        total_sum = sum(arr)
        if target < -total_sum or target > total_sum: # not possible to acheive target
            return 0
        
        # make a offset value to handle -ve index
        offset = total_sum
        dp = [[0] * (2 * total_sum + 1) for _ in range(n + 1)]
        
        # Base case: for row n if col == target then ways = 1 else 0
        dp[n][target + offset] = 1
        # start filling from n-1 index to 0 cause n-th index is aleady done
        for index in range(n - 1 , -1 , -1):
            for curr_value in range(-total_sum , total_sum + 1):
                normalized_curr = curr_value + offset
                
                if 0 <= normalized_curr + arr[index] <= 2 * total_sum:
                    dp[index][normalized_curr] += dp[index + 1][normalized_curr + arr[index]]
                if 0 <= normalized_curr - arr[index] <= 2 * total_sum:
                     dp[index][normalized_curr] += dp[index + 1][normalized_curr - arr[index]]
        
        return dp[0][0 + offset]
                
sol = Solution()
arr = [1,1,1,1,1]    
target = 3

print(sol.findTargetSumWays(arr , target))            