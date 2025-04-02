from typing import List

class Solution:
    def maximumTripletValue(self, arr: List[int]) -> int:
        
        # For every element i need the next smallest element index
        # After the next smallest element i need the next greater element index
        
        # Always track the previous max element
        # Make a prefix array which will store the next largest element for every index
        n = len(arr)
        next_largest = [0] * n 
        
        index = n - 2
        next_max = arr[n-1]
        
        while index >= 0:
            next_largest[index] = next_max
            next_max = max(next_max , arr[index])
            index -= 1
        
        # print(next_largest)    
        
        prev_max_element = arr[0]
        ans = 0
        
        for i in range(1 , n):
            curr_val = (prev_max_element - arr[i]) * next_largest[i]
            ans = max(ans , curr_val)
            prev_max_element = max(prev_max_element , arr[i])
        
        return ans  
        
        
sol = Solution()

print(sol.maximumTripletValue([12,6,1,2,7]))
print(sol.maximumTripletValue([1,10,3,4,19]))
print(sol.maximumTripletValue([1,2,3]))
print(sol.maximumTripletValue([1 , 14 , 12 , 3 , 4 , 11 , 9]))        