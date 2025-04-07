from typing import List

class Solution:
    def canPartition(self, arr: List[int]) -> bool:
        total_sum = sum(arr)
        
        # odd sum array can't be divided into 2 equal parts 
        if total_sum % 2 != 0:
            return False
        
        target = total_sum // 2
        n = len(arr)
        
        dp = [[-1] * (target + 1) for _ in range(n)]
        
        def solve(index: int , curr_sum: int) -> bool:
            # if we get the target sum
            if curr_sum == 0:
                return True
            
            if index >= n or curr_sum < 0:
                return False
            
            if dp[index][curr_sum] != -1:
                return True if dp[index] == 1 else False
            
            # take the currIndex element
            include = solve(index + 1 , curr_sum - arr[index])
            # don't take the currIndex element
            exclude = solve(index + 1 , curr_sum)
            
            dp[index][curr_sum] = 1 if (include or exclude) else 0
            
            return include or exclude
        
        return solve(0 , target)
        


sol = Solution()

print(sol.canPartition([1,5,11,5]))
print(sol.canPartition([1,2,3,5]))
print(sol.canPartition([1,2,3,4]))        