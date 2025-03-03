from typing import List

class Solution:
    def pivotArray(self, arr: List[int], pivot: int) -> List[int]:
        # Traverse the array 2 times.
        # First, move all elements less than pivot to the front.
        # Then, move all elements equal to pivot next.
        # The remaining elements are automatically greater than the pivot.
        n = len(arr)
        low = 0
        # Take elements which is less than pivot
        for i in range(n):
            if arr[i] < pivot:
                # Swapping small element
                arr[low] , arr[i] = arr[i] , arr[low]
                low += 1
        # Take elements which is equal to pivot
        equal = low 
        for i in range(low , n):
            if arr[i] == pivot:
                arr[i] , arr[equal] = arr[equal] , arr[i]
                equal += 1
        
        return arr         
                
sol = Solution()

nums = [9,12,5,10,14,3,10]
print(sol.pivotArray(nums , 10))

nums = [-3,4,3,2]                
print(sol.pivotArray(nums , 2)) 