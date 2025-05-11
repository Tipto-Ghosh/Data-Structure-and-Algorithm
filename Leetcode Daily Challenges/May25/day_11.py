from typing import List

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        """
        1. Iterate through every element of the array
        2. If element is odd then increase the odd_count
        3. If element is even then reset the odd_count
        4. If odd_count becomes 3 then return True
        """
        
        odd_count = 0
        
        for ele in arr:
            if ele % 2 == 1:
                odd_count += 1
                if odd_count == 3:
                    return True
            else:
                odd_count = 0
        
        return False
    
sol = Solution()

print(sol.threeConsecutiveOdds([2,6,4,1]))
print(sol.threeConsecutiveOdds([1,2,34,3,4,5,7,23,12]))        