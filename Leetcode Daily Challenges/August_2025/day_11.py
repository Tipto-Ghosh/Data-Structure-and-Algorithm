from typing import List

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        mod = 10**9+7
        powers = []
        for i in range(32):
            if n&(1<<i)!=0:
                powers.append(1<<i)
        
        res = []
        for u,v in queries:
            mul = 1
            for i in range(u,v+1):
                mul = mul * powers[i]
                mul %= mod
            res.append(mul)
            
        return res

sol = Solution()
print(sol.productQueries(n = 15, queries = [[0,1],[2,2],[0,3]]))