from typing import List
from collections import defaultdict
class Solution:
    def countCompleteSubarrays(self, arr: List[int]) -> int:
        # Count the total number distinct elements of the array
        total_distinct_count = len(set(arr))
        
        n = len(arr)
        count = 0
        
        # start from every index i as a starting of a sub-array
        for i in range(n):
            freq = defaultdict(int) # Count frequency of elements in the current sub-array
            distinct = 0 # count the distinct we have got so far in the current sub-array
            
            # Expand the sub-array                        
            for j in range(i , n):
                if freq[arr[j]] == 0:
                    # arr[j] is a distinct element
                    distinct += 1
                freq[arr[j]] += 1
                
                # we have got desired distinct elemnts
                if distinct == total_distinct_count:
                    count += 1
            
            
        return count
        
        
sol = Solution()

print(sol.countCompleteSubarrays([1,3,1,2,2]))
print(sol.countCompleteSubarrays([5,5,5,5])) 