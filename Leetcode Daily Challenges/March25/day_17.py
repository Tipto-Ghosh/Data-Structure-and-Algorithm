# Created By: Tipto Ghosh
# Creation Time: 2025/03/17 07:21:26

from typing import List

class Solution:
    def divideArray(self, arr: List[int]) -> bool:
        count = {}
        for ele in arr:
            count[ele] = count.get(ele , 0) + 1
        
        for val in count.values():
            if val % 2 != 0:
                return False
        
        return True
    

sol = Solution()

print(sol.divideArray([3,2,3,2,2,2,2,1]))
print(sol.divideArray([1,2,3,4]))