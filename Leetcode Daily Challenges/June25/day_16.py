from typing import List

class Solution:
    def maximumDifference(self, arr: List[int]) -> int:
        # Track the min element from the left and move to right
        # Always do curr_ele - left_min --> curr_diff
        # Take make of and and curr_diff
        # Then update min_left if curr_ele is less than left_min
        
        n = len(arr)
        max_diff = -float('INF')
        left_min = arr[0]
        
        for i in range(1 , n):
            # If curr element is greater than left_min
            if arr[i] > left_min:
               max_diff = max(max_diff , arr[i] - left_min)
            else:
                left_min = arr[i]
        
        return -1 if max_diff == -float('INF') else max_diff
    
        
sol = Solution()

print(sol.maximumDifference([7,1,5,4]))
print(sol.maximumDifference([9,4,3,2]))
print(sol.maximumDifference([1,5,2,10]))        