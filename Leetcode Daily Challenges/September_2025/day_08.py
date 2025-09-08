from typing import List 
from collections import Counter
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        ans = []
        
        for a in range(1 , n):
            counter_a = Counter(str(a))
            # if a is not a non-zero number then skip it
            if '0' in counter_a:
                continue
            
            b = n - a 
            # check if b is a non-zero or not
            counter_b = Counter(str(b))
            if '0' not in counter_b:
                ans = [a , b]
                break 
        
        return ans

sol = Solution()

print(sol.getNoZeroIntegers(2))
print(sol.getNoZeroIntegers(11))
print(sol.getNoZeroIntegers(112)) 
print(sol.getNoZeroIntegers(1010)) 
