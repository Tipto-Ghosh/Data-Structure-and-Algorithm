# from collections import defaultdict
# class Solution:
#     def countPartitions(self, arr, d):
#        n = len(arr)        
#        dp = defaultdict(int)
#        def solve(index: int , sum1: int , sum2: int) ->int:
#            if index == n:
#                return 1 if sum1 - sum2 == d else 0
#            if (index , sum1 , sum2) in dp:
#                return dp[(index , sum1 , sum2)]
#            # for an element we have 2 choice
#            exclude = solve(index + 1 , sum1 , sum2)
#            include = 0
#            if sum1 + arr[index] - sum2 <= d:
#               include = solve(index + 1 , sum1 + arr[index] , sum2 - arr[index])
#            dp[(index , sum1 , sum2)] = exclude + include
#            return exclude + include
#        total = sum(arr)
#        return solve(0 , 0 , total)
   
# sol = Solution()
# arr = [5,2,6,4]
# d = 3
# arr2 = [1, 2, 1, 0, 1, 3, 3]
# print(sol.countPartitions(arr2 , 11))


from typing import List
mod = 10e9 + 7
def countPartitions(n: int, d: int, arr: List[int]) -> int:
    # I have to find to subset where abs(subset1 - sebset2) = d
    # In another word find a target_sum = (total_sum - d) // 2
    total_sum = sum(arr)
    target_sum = (total_sum - d) // 2
    
    def solve(index: int , target: int) -> int:
        if index == n:
            return 1 if target == 0 else 0
        
        # for each element i have 2 choice take or skip
        skip = solve(index + 1 , target)
        take = 0
        if target >= arr[index]:
            take = solve(index + 1 , target - arr[index])
        
        ans = ((take % mod) + (skip % mod)) % mod
        return ans
    return solve(0 , target_sum) 
    

n = 4
d = 3
arr = [5 , 2 , 6 , 4]

print(countPartitions(n , d , arr))