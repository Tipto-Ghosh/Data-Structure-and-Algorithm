from typing import List
from collections import defaultdict

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        # pair if (a == c and b == d), or (a == d and b == c) 
        map = defaultdict(int)
        
        count = 0
        
        for a , b in dominoes:
            # MAke the key
            key = tuple(sorted((a, b)))
            # find how many (a , b) pair possible
            count += map[key]
            
            # add the current pair
            map[key] += 1
        
        return count
                    
sol = Solution()

print(sol.numEquivDominoPairs([[1,2],[2,1],[3,4],[5,6]]))
print(sol.numEquivDominoPairs([[1,2],[1,2],[1,1],[1,2],[2,2]]))        