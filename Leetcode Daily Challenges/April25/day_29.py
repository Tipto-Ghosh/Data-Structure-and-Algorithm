from typing import List

class Solution:
    def countSubarrays(self, arr: List[int], k: int) -> int:
        # Find the max element
        max_ele = max(arr) 
        n = len(arr)
        count_max_ele = 0 # max element count in the current window
        ans = 0
        
        left = 0
        
        for right in range(n):
            if arr[right] == max_ele:
                count_max_ele += 1
            
            while count_max_ele >= k:
                ans += (n - right)
                if arr[left] == max_ele:
                    count_max_ele -= 1
                left += 1
        
        return ans 
        
sol = Solution()

print(sol.countSubarrays([1,3,2,3,3] , 2))