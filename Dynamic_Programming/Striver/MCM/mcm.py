# Whenever there are multiple ways to solve a question and asking for an optimaized or minimal way
# we will use partition dp / mcm dp

# Partition Dp Steps:
# 1. Start with entire block/array. represent start as i and end as j
# 2. Try all partitions[run a loop to try all partition]
# 3. Return the best possible 2 partition

def matrixMultiplication(arr, n):
    # dp = [[-1] * n for _ in range(n)]
    # def solve(i , j) -> int: # i is that start and j is the end
    #     # Base Case: only one matrix
    #     if i == j:
    #         return 0
    #     if dp[i][j] != -1:
    #         return dp[i][j]    
    #     ans = float('inf')
    #     # start partitioning from start to end
    #     for k in range(i , j):
    #         sub_ans = solve(i , k) + solve(k + 1 , j) + arr[i-1] * arr[k] * arr[j]
    #         ans = min(ans , sub_ans)
        
    #     dp[i][j] = ans
    #     return ans
    
    # return solve(1 , n - 1)    
    
    # Solve Using Tabulation
    dp = [[0] * n for _ in range(n)] # or we can also make a loop for i in range(n) set dp[i][i] = 0
    
    for length in range(2 , n):
        for i in range(1 , n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            
            for k in range(i , j):
                cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]
                dp[i][j] = min(dp[i][j] , cost)
    
    return dp[1][n-1]    