from typing import List

class Solution:
    def longestNiceSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        used_bits = 0 # track bits used in current window
        start = 0 # starting position of current window
        max_len = 1
        
        for end in range(n):
            # if current window share bits with window then shrink the window
            while used_bits & arr[end] != 0:
                used_bits = used_bits ^ arr[start]
                start += 1
            
            # now we have an valid window so add the current element
            used_bits |= arr[end]
            max_len = max(max_len , end - start + 1)    
        
        return max_len
        
sol = Solution()
        
print(sol.longestNiceSubarray([1,3,8,48,10]))
print(sol.longestNiceSubarray([3,1,5,11,13]))