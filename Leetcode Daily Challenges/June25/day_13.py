from typing import List

from typing import List

class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()

        def can_form_pairs(max_diff: int) -> bool:
            i = 0
            count = 0
            while i < len(nums) - 1:
                if nums[i + 1] - nums[i] <= max_diff:
                    count += 1
                    i += 2  # Skip both elements to ensure no overlap
                else:
                    i += 1
            return count >= p

        # Binary search
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = (left + right) // 2
            if can_form_pairs(mid):
                right = mid
            else:
                left = mid + 1
        return left
                 
                  
        
sol = Solution()

print(sol.minimizeMax([10,1,2,7,1,3], p = 2))
print(sol.minimizeMax([4,2,1,2], p = 1))                