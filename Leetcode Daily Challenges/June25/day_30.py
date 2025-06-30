from typing import List

class Solution:
    def findLHS(self, arr: List[int]) -> int:
        n = len(arr)
        arr.sort()
        
        left = 0
        max_len = 0
        
        for right in range(n):
            while arr[right] - arr[left] > 1:
                left += 1
        
            if arr[right] - arr[left] == 1:
                max_len = max(max_len , right - left + 1)
        
        return max_len    
             