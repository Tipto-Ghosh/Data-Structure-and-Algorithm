from typing import List
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return (m * n) // 2
    
sol = Solution()
print(sol.flowerGame(3 , 2))