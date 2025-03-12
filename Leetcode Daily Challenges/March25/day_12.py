from typing import List

class Solution:
    def maximumCount(self, arr: List[int]) -> int:
        # Start from 0 and count all the -ve numbers
        # Then run a loop to skip the 0's
        # Then +ve number count = n - index
        
        n = len(arr)
        neg_count = 0
        index = 0
        
        # Count all the -ve numbers
        while index < n and arr[index] < 0:
            neg_count += 1
            index += 1
        
        # Skip the 0's
        while index < n and arr[index] == 0:
            index += 1
        
        # Count the +ve numbers
        pos_count = n - index 
        return max(neg_count , pos_count)
        
        
sol = Solution()        

print(sol.maximumCount([-2,-1,-1,1,2,3]))

print(sol.maximumCount([-3,-2,-1,0,0,1,2]))        
        
print(sol.maximumCount([5,20,66,1314]))