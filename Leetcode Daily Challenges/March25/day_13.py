# Created By: Tipto Ghosh
# Creation Time: 2025/03/13 07:56:50

from typing import List
class Solution:
    def minZeroArray(self, arr: List[int], queries: List[List[int]]) -> int:
        # If array is already a zro array
        if all(x == 0 for x in arr):
            return 0
       # K can be from 1 to query_len + 1 or k = 0 to query_len - 1[in terms of index]
        queryCount = -1
       
        def apply_query(mid):
            n = len(arr)
            diff = [0] * (n + 1)
            # Index 0 to mid
            for i in range(mid + 1):
                left , right , val = queries[i]
                diff[left] += val 
                if right + 1 < n:
                   diff[right + 1] -= val 
           
            curr_decrement = 0
            for i in range(n):
               curr_decrement += diff[i]
               arr[i] = max(0 , arr[i] - curr_decrement)
               
               
        def is_zero_array()->bool:
           for i in range(len(arr)):
               if arr[i] != 0:
                   return False
           return True
                   
        l , r = 0 , len(queries) - 1
        while l <= r:
           mid = l + (r - l) // 2
           temp_arr = arr[:]
           # Use queries from 0 to mid
           apply_query(mid)
           # Now check is all value is less than equal zero or not
           if is_zero_array():
               # We got a valid answer now save it try to get more lower value
               queryCount = mid 
               r = mid - 1
           else:
               # We need to use more num of queries
               l = mid + 1
           arr = temp_arr[ : ]
        return queryCount + 1 if queryCount != -1 else -1
   
# Example usage
sol = Solution()

# Test case 1
arr1 = [2, 0, 2]
queries1 = [[0, 2, 1], [0, 2, 1], [1, 1, 3]]
print(f"Test Case 1 Output: {sol.minZeroArray(arr1, queries1)}")  # Expected Output: 2

# Test case 2
arr2 = [4, 3, 2, 1]
queries2 = [[1, 3, 2], [0, 2, 1]]
print(f"Test Case 2 Output: {sol.minZeroArray(arr2, queries2)}")  # Expected Output: -1