from typing import List

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        arr = []
        ans = 0
        
        # make a single diamensional array
        for r in range(len(grid)):
            for c in range(len(grid[r])):
                arr.append(grid[r][c])
        
        arr.sort()
        
        length = len(arr)
        # Take the median elements which will be the candidate as the univalue
        medianElement = arr[length // 2]
        rem = medianElement % x
        for ele in arr:
            if ele % x != rem:
                return -1
            
            diff = abs(medianElement - ele) 
            operations = diff // x 
            ans +=  operations
        
        return ans
                
                
sol = Solution()

print(sol.minOperations([[2,4],[6,8]] , 2))
print(sol.minOperations([[1,5],[2,3]] , 1))
print(sol.minOperations([[1,2],[3,4]] , 2))                