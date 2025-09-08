from typing import List

class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        
        # n is odd then add zero
        if n % 2 == 1:
           ans.append(0)
           n -= 1
        
        # now n is even. so add pairs of (+ve , -ve) 
        num = 1
        while len(ans) < n:
            ans.append(num)
            ans.append(-num)
            num += 1
            
        return ans 
    
sol = Solution()
print(sol.sumZero(5))
print(sol.sumZero(3))
print(sol.sumZero(1))  