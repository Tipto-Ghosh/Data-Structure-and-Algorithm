from typing import List
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        
        count = 0
        
        for i in range(n - 1 , -1 , -1):
            j , k = 0 , i - 1
            
            while j < k:
                if nums[j] + nums[k] > nums[i]:
                    count += (k - j) # all the elements from j to k
                    k -= 1
                else:
                    j += 1
        return count 
    
sol = Solution()

print(sol.triangleNumber([2,2,3,4]))
print(sol.triangleNumber([4,2,3,4]))