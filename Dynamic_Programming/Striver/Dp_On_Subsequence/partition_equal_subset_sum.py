from typing import List
class Solution:
    def canPartition(self, arr: List[int]) -> bool:
        # # find the total sum. Our target is to get a subset which sum is equal to half of total sum
        # total_sum = sum(arr)
        # target_sum = total_sum // 2
        # # we can't divided a odd number in 2 equal groups        
        # if total_sum & 1:
        #     return False
        
        # n = len(arr)
        # dp = [[-1] * (target_sum + 1) for _ in range(n)]
        
        # def solve(index: int , curr_sum: int) -> bool:
        #     if index == n:
        #         return curr_sum == target_sum
        #     if curr_sum == target_sum:
        #         return True
        #     if dp[index][curr_sum] != -1:
        #         return dp[index][curr_sum] # we can store different types also no issue
        #     take = False
        #     if curr_sum + arr[index] <= target_sum:
        #         take = solve(index + 1 , curr_sum + arr[index])
        #     skip = solve(index + 1 , curr_sum)
        #     dp[index][curr_sum] = take or skip
        #     return dp[index][curr_sum]    
        
        # return solve(0 , 0)    
        n = len(arr)
        total_sum = sum(arr)
        target_sum = total_sum // 2
        # we can't divided a odd number in 2 equal groups        
        if total_sum & 1:
            return False
        dp = [[-1] * (total_sum + 1) for _ in range(n + 1)]
        # initialization of base case's
        
        
        

sol = Solution()
nums1 = [1,5,11,5]   
nums2 = [1,2,3,5]
print(sol.canPartition(nums1))
print(sol.canPartition(nums2))

# n = 13

# if n & 1:
#     print("odd")
# else:
#     print("Even")    
