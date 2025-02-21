class Solution:
	def  perfectSum(self, arr, target):
        # for each index we have 2 choice include or exclude
        #  n = len(arr)
        #  dp = [[-1] * (target + 1) for _ in range(n)]
        #  def solve(index: int , curr_sum: int) -> int:
        #     # base case
        #     if index == n:
        #         return 1 if curr_sum == target else 0
        #     if dp[index][curr_sum] != -1:
        #         return dp[index][curr_sum]
            
        #     # exclude the curr element
        #     exclude = solve(index + 1 , curr_sum)
        #     # include the curr element
        #     include = 0
        #     if arr[index] + curr_sum <= target:
        #         include = solve(index + 1 , arr[index] + curr_sum)
            
        #     dp[index][curr_sum] = include + exclude
        #     return dp[index][curr_sum]
        #  return solve(0 , 0)
     
        # -------------- using Tabulation Method-----------------
         n = len(arr)
         dp = [[0] * (target + 1) for _ in range(n + 1)]
         
         # if curr_sum == target for the last row then it should be 1 else 0
         # if target is 0 then there is only 1 subset[empty subset so count 1]
         for i in range(n + 1):
             dp[i][0] = 1
         
         for i in range(n - 1 , -1 , -1):
             for j in range(target + 1):
                 dp[i][j] = dp[i + 1][j]
                 if j >= arr[i]:
                     dp[i][j] += dp[i + 1][j - arr[i]] 
         return dp[0][target]                 

sol = Solution()         
arr = [5, 2, 3, 10, 6, 8]
target = 10

print(sol.perfectSum(arr , target))