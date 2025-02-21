class Solution:
    def knapSack(self, capacity, val, wt):
        # n = len(val)
        # dp = [[-1] * (capacity + 1) for _ in range(n)]
        # def solve(index: int , curr_capacity: int) -> int:
        #     if index == 0:
        #         return val[0] if curr_capacity >= wt[0] else 0
        #     if dp[index][curr_capacity] != -1:
        #         return dp[index][curr_capacity]
            
        #     skip = solve(index - 1 , curr_capacity)
        #     take = 0
        #     if curr_capacity >= wt[index]:
        #         take = val[index] + solve(index - 1 , curr_capacity - wt[index])
                
        #     dp[index][curr_capacity] = max(take , skip)
        #     return dp[index][curr_capacity]
        # return solve(n-1 , capacity)
        
        # Base case
        # for every ele in the 0-th index if capacity is greater than ele then we can take it
        # n = len(val)
        # dp = [[0] * (capacity + 1) for _ in range(n)]
        # for w in range(capacity + 1): # we can take the 0-th item if capacity allows
        #     if w >= wt[0]:
        #         dp[0][w] = val[0]
        
        # for i in range(1 , n):
        #     for w in range(capacity + 1):
        #         skip = dp[i-1][w]
        #         take = 0
        #         if w >= wt[i]:
        #             take = val[i] + dp[i-1][w - wt[i]]
        #         dp[i][w] = max(take , skip)
        # return dp[n-1][capacity]        
        
        #------------Space Optimization--------------------
        n = len(val)
        prev = [0] * (capacity + 1)
        curr = [0] * (capacity + 1)     
        for w in range(capacity + 1): # we can take the 0-th item if capacity allows
            if w >= wt[0]:
                prev[w] = val[0]
        
        for i in range(1 , n):
            for w in range(capacity + 1):
                skip = prev[w]
                take = 0
                if w >= wt[i]:
                    take = val[i] + prev[w - wt[i]]
                curr[w] = max(take , skip)
            prev = curr
        return prev[capacity]        
        
sol = Solution()
val = [10 , 40 , 30 , 50]
wt = [5 , 4 , 6 , 3]

print(sol.knapSack(4 , val , wt))