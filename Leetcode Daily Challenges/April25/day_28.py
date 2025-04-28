# Created By: Tipto Ghosh
# Creation Time: 2025/04/28 19:23:16


from typing import List

class Solution:
    def countSubarrays(self, arr: List[int], k: int) -> int:
        # Make a variable length window
        # Till sum * length < k --> expand the window and count the sub-array
        # If sum * length >= k --> start shrinking the window
        ans = 0
        n = len(arr)
        left = 0
        curr_sum = 0
        
        for right in range(n):
            # take the curr_ele
            curr_sum += arr[right]
            # start shrinking the window
            while  (right - left + 1) * curr_sum >= k:
                curr_sum -= arr[left]
                left += 1 
            
            # now we have a valid window
            ans += (right - left + 1)    
        
        return ans 
        
        
sol = Solution()

print(sol.countSubarrays([2,1,4,3,5] , 10))
print(sol.countSubarrays([1,1,1] , 5))        