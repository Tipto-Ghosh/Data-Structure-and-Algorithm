# Created By: Tipto Ghosh
# Creation Time: 2025/03/19 18:35:14


from typing import List

class Solution:
    def minOperations(self, arr: List[int]) -> int:
        # Find the position of first zero
        # Then start iterating from index_zero to end of the arr
        # If next 3 element is non-zero then skip it
        # If we got an index where element is 0 then flip the next 3 elements
        # Simulate this untill we have less than 3 elements 
        # At the end if we have any zero left then return -1
        # Else count the operations
        
        n = len(arr)
        count_operations = 0
        # Find the first zero
        first_zero = 0
        while first_zero < n and arr[first_zero] != 0:
            first_zero += 1
        
        # If no zero found or we have less then 3 elements
        if first_zero == n:
            return 0
        
        right_index = first_zero
        while right_index <= n - 3:
            # If right_index element is 0 then flip the next 3 elements
            if arr[right_index] == 0:
                count_operations += 1
                arr[right_index] = 1 
                arr[right_index + 1] = 1 if arr[right_index + 1] == 0 else 0
                arr[right_index + 2] = 1 if arr[right_index + 2] == 0 else 0
            # If we are at a non-zero element then skips all the elements untill we found a zero
            right_index += 1
            # while right_index < n and arr[right_index] != 0:
            #     right_index += 1
        
        # If any zero left then return -1
        for ele in arr:
            if ele == 0:
                return -1
        
        return count_operations 


sol = Solution()

print(sol.minOperations([0,1,1,1,0,0]))

print(sol.minOperations([1,0,0]))        