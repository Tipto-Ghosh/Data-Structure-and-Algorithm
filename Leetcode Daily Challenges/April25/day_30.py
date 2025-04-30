from typing import List

class Solution:
    def findNumbers(self, arr: List[int]) -> int:
        # possible length of number can be 1 to 6 [included]
        # even --> 2 , 4 , 6
        # 2 digit --> 10 to 99
        # 4 digits --> 1000 to 9999
        # 6 digits --> 100000 to 999999
        count = 0
        
        for num in arr:
            if (10 <= num < 100) or (1000 <= num <= 9999) or (100000 <= num <= 999999):
                count += 1
        
        return count   
        

sol = Solution()
print(sol.findNumbers([12,345,2,6,7896]))
print(sol.findNumbers([555,901,482,1771]))