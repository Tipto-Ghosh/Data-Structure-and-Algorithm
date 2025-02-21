from typing import List
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:

       dp = {}
       def solve(l , r) -> int:
           if r - l == 1: # rof length is 1 so no cuts are possible
               return 0
            
           if (l , r) in dp:
               return dp[(l , r)]
           ans = float('inf')
           for cut in cuts:
               # ensure cuts are possible
               if l < cut < r:
                   curr = r - l + solve(l , cut) + solve(cut , r)
                   ans = min(ans , curr)
           
           ans = 0 if ans == float('inf') else ans
           dp[(l , r)] = ans
           return ans
       return solve(0 , n)
    
                                 

sol = Solution()
cuts = [1,3,4,5]

print(sol.minCost(7 , cuts))