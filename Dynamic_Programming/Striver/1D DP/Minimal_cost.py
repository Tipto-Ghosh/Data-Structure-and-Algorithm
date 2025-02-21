class Solution:
    def minimizeCost(self, k, arr):
        """
        n = len(arr)
        # we have to reach at index n - 1
        # we can jump 1 to k if it is in the valid range/position [n-1]
        dp = [-1] * n
        def solve(index: int) -> int:
            # base case: 
            # if we reached
            if index >= n - 1:
                return 0
            # add memo here
            if dp[index] != -1:
                return dp[index]            
            ans = float('inf')
            valid_jump = 1
            while valid_jump <= k and valid_jump + index < n:
                sub_ans = abs(arr[index] - arr[index + valid_jump]) + solve(index + valid_jump)
                ans = min(ans , sub_ans)
                valid_jump += 1
            dp[index] = ans
            return ans
        return solve(0) """
        # solve using tabulation
        n = len(arr)
        # dp[i] represents the minimum cost to reach the last index from i
        dp = [float('inf')] * n
        dp[n-1] = 0 # we reached at the end no cost needed[cost to reach last index from last index]
        
        # from 2nd-last to first index: n - 2 to 0
        for i in range(n - 2 , -1 , -1):
            # calculate the cost for jump 1 to k
            for j in range(1 , k + 1):
                if i + j < n: # we are in valid index
                    dp[i] = min(dp[i] , abs(arr[i] - arr[i + j]) + dp[i + j])
        return dp[0]            
sol = Solution()
arr = [10 , 20 , 10]
k = 1

print(sol.minimizeCost(k , arr))    