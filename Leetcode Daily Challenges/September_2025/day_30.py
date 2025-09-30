from typing import List 

class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        
        for i in range(n - 1):
            temp = []
            for j in range(len(nums) - 1):
                temp.append((nums[j] + nums[j + 1]) % 10)
            nums = temp
        
        return nums[0]
    
sol = Solution()

print(sol.triangularSum([1,2,3,4,5]))
print(sol.triangularSum([5]))
print(sol.triangularSum([2,3]))    