from typing import List

class Solution:
    def countFairPairs(self, arr: List[int], lower: int, upper: int) -> int:
        arr.sort()
        n = len(arr)
        count = 0
        
        # Go to every element
        for i in range(n):
            # Find the min_element which min_element + curr_element >= lower
            min_index = n
            left , right = i + 1 , n - 1
            while left <= right:
                mid = left + (right - left) // 2
                if arr[i] + arr[mid] >= lower:
                    # We got a valid number index
                    min_index = mid 
                    # Find more smaller value
                    right = mid - 1
                else:
                    # Find more larger value
                    left = mid + 1
            # Find the max_element which max_element + curr_element <= upper
            max_index = i 
            left , right = i + 1 , n - 1
            while left <= right:
                mid = left + (right - left) // 2
                if arr[i] + arr[mid] <= upper:
                    # We got a valid number index
                    max_index = mid 
                    # Find more larger value
                    left = mid + 1
                else:
                    # Find more smaller value
                    right = mid - 1
            
            if min_index <= max_index:
                count += (max_index - min_index + 1)
        
        return count
    
sol = Solution()
print(sol.countFairPairs([0,1,7,4,4,5] , 3 , 6))