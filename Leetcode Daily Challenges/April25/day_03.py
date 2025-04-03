from typing import List

class Solution:
    def maximumTripletValue(self, arr: List[int]) -> int:
        n = len(arr)
        nextLargestElement = [0] * n 
        next_largest = arr[-1]
        index = n - 2
        while index >= 0:
            nextLargestElement[index] = next_largest
            next_largest = max(next_largest , arr[index])
            index -= 1
        
        # print(nextLargestElement)
        
        prev_largest = arr[0]
        ans = 0
        for i in range(1 , n):
            curr_val = (prev_largest - arr[i]) * nextLargestElement[i]
            ans = max(ans , curr_val)
            prev_largest = max(arr[i] , prev_largest)
        
        return ans 
         
        
        
        
sol = Solution()

print(sol.maximumTripletValue([12,6,1,2,7]))
print(sol.maximumTripletValue([1,10,3,4,19]))
print(sol.maximumTripletValue([1,2,3]))
print(sol.maximumTripletValue([1 , 14 , 12 , 3 , 4 , 11 , 9]))                        