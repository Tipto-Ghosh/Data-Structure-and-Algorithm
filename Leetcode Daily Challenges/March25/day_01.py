from typing import List

class Solution:
    def applyOperations(self, arr: List[int]) -> List[int]:
        n = len(arr)
        # Problem Intution:
        
        # all element >= 0
        # exact n-1 operations
        # apply loop and do as the question said for first part
        # Then move zeroes
        
        # First Part
        for i in range(1 , n):
            if arr[i] == arr[i - 1]:
                arr[i] = 0
                arr[i - 1] *= 2
        
        # Now Move the zeros
        # We will apply 2 pointer approch
        # Count all zeros
        count_zero = 0
        zero_index = -1 # Find the first 0
        for i in range(n):
            if arr[i] == 0:
                count_zero += 1
                if zero_index == -1:
                    zero_index = i
        
        if count_zero == 0:
            return arr
        for i in range(zero_index + 1 , n):
            if arr[i] != 0:
                arr[zero_index] = arr[i]
                zero_index += 1
        # start filling zero from the last and exact count_zero times
        for i in range(n-1 , -1 , -1):
            arr[i] = 0
            count_zero -= 1
            if count_zero == 0:
                break
            
        return arr
        


sol = Solution()
nums = [1,2,2,1,1,0]
print(sol.applyOperations(nums))
        
nums = [0,1]        
print(sol.applyOperations(nums))        
