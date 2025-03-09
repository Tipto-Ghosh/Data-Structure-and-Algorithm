from typing import List

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        
        n = len(colors)
        count = 0
        valid_len = 1 # Start with the first element
        
        # As we have done the first element so now start from the index 1
        for i in range(1 , n + k - 1):
            if colors[i % n] != colors[(i - 1) % n]:
                valid_len += 1
            else:
                valid_len = 1
            
            if valid_len >= k:
                count += 1
        
        return count
        
        
        
        
sol = Solution()

print(sol.numberOfAlternatingGroups([0,1,0,1,0] , 3)) # ans: 3
print(sol.numberOfAlternatingGroups([0,1,0,0,1,0,1] , 6)) # ans: 2
print(sol.numberOfAlternatingGroups([1,1,0,1] , 4)) # ans: 0       