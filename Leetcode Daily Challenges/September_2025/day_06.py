from typing import List
import math

class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        
        def total_steps_in_range(l: int , r: int) -> int:
            """returns total steps for all numbers [l , r]"""
            total = 0
            # Go through ranges of form [4^(k-1), 4^k - 1]
            k = 1
            start = 1
            
            while start <= r:
                end = min(r , 4**k - 1)
                if end >= l:
                    # overlap with [l , r]
                    overlap_l = max(l , start)
                    overlap_r = end 
                    
                    count = overlap_r - overlap_l + 1
                    if count > 0:
                        total += count * k 
                k += 1
                start = 4 ** (k - 1)
            
            return total
        
        total_ops = 0
        for l , r in queries:
            steps = total_steps_in_range(l, r)
            ops = (steps + 1) // 2   # ceil(steps / 2)
            total_ops += ops
        
        return total_ops
     
sol = Solution()

print(sol.minOperations([[2,6]]))        