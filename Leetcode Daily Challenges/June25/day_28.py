from typing import List

class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        values = [[nums[i] , i] for i in range(len(nums))]
        # print(values)
        
        values = sorted(values , reverse = True)
        # print(values)
        
        take = [values[i] for i in range(k)]
        
        
        take = sorted(take , key = lambda x: x[1])
        
        return [take[i][0] for i in range(len(take))]
        
sol =  Solution()
print(sol.maxSubsequence([2,1,3,3] , 2))    
print(sol.maxSubsequence(nums = [-1,-2,3,4], k = 3))    