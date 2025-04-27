from typing import List

class Solution:
    def countSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        count = 0
        
        for i in range(2 , n):
            first_ele = arr[i - 2]
            second_ele = arr[i-1]
            third_ele = arr[i]
            # print([first_ele , second_ele , third_ele , (first_ele + third_ele)])
            if arr[i-2] + arr[i] == arr[i-1] / 2:
                count += 1
        
        return count
        

sol = Solution()
print(sol.countSubarrays([1,2,1,4,1]))
print(sol.countSubarrays([1,1,1]))
# print(sol.countSubarrays())        