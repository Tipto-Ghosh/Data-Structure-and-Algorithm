from typing import List

class Solution:
    def pivotArray(self, arr: List[int], pivot: int) -> List[int]:
        # Traverse the array 3 times.
        # First take all elements less than pivot
        # Then  take all elements equal to pivot
        # After that take all elements greater than pivot
        ans = []
        # Take elements which is less than pivot
        for ele in arr:
            if ele < pivot:
                ans.append(ele)
        # Take elements which is equal to pivot
        for ele in arr:
            if ele == pivot:
                ans.append(ele)
        # Take elements which is greater than pivot
        for ele in arr:
            if ele > pivot:
                ans.append(ele)
                
        return ans       
                
                
sol = Solution()

nums = [9,12,5,10,14,3,10]
print(sol.pivotArray(nums , 10))

nums = [-3,4,3,2]                
print(sol.pivotArray(nums , 2)) 