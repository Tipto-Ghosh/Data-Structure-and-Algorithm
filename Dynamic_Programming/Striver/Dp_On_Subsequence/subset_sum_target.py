from collections import defaultdict
class Solution:
    def isSubsetSum (self, arr, target):
        # for evey ele I have 2 choice take or skip
        # if curr_sum + ele > target we can't take it. But we can always skip one value
        # n = len(arr)
        
        # dp = defaultdict(bool)
        
        # def solve(index: int , curr_sum: int) -> bool:
        #     if index >= n:
        #         return curr_sum == target
        #     if curr_sum == target:
        #         return True
               
        #     if (index , curr_sum) in dp:
        #         return dp[(index , curr_sum)]
            
        #     skip = solve(index + 1 , curr_sum)
        #     take = False
        #     if curr_sum + arr[index] <= target:
        #         take = solve(index + 1 , curr_sum + arr[index])
        #     dp[(index , curr_sum)] = skip or take
        #     return dp[(index , curr_sum)]           
        # return solve(0 , 0)
        
        # Tabulation
        n = len(arr)
        total = sum(arr)
        if total % 2 == 1:
            return False
        target = total // 2
        dp = [[False] * (target + 1) for _ in range(n)]
        # at any index if target is 0 then answer is true
        for index in range(n):
            dp[index][0] = True
        # 2nd based case if index is 0 then return target == 0
        # if index is 0 and target is any-thing then False if target == arr[0] then True
        dp[0][arr[0]] = True
        # form the nested loop
        for index in range(1 , n):
            for value in range(1 , target + 1): # 0 already done so 1 to target
                take = False
                if arr[index] <= target:
                    take = dp[index - 1][value - arr[index]]
                skip = dp[index - 1][value]
                dp[index][value] = take or skip
        return dp[n-1][target]
                
sol = Solution()
arr = [3, 34, 4, 12, 5, 2]
target = 30

print(sol.isSubsetSum(arr , target))