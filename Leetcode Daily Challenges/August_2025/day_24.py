from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        left , right , zero_count , max_len = 0 , 0 , 0 , 0
        
        # move the right pointer
        while right < n:
            if nums[right] == 0:
                zero_count += 1
                
            # if we have more than 1 zero
            while zero_count > 1:
                # shrink the window
                if nums[left] == 0:
                    zero_count -= 1
                left += 1
            
            # now count the window length
            max_len = max(max_len , right - left)
            # move the right pointer
            right += 1
        
        return max_len
    

sol = Solution()

print(sol.longestSubarray([0,1,1,1,0,1,1,0,1]))