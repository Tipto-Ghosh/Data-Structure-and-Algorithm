from typing import List
from collections import defaultdict
class Solution:
    def countPairs(self, arr: List[int], k: int) -> int:
        n = len(arr)
        map = defaultdict(list) # key(element) --> value(indices where element is present)
        
        count = 0
        
        for i in range(n):
            # count the pairs
            # print(map[arr[i]])
            for j in map[arr[i]]:
                if i * j % k == 0:
                    count += 1
            map[arr[i]].append(i)
            
        return count
        
        
sol = Solution()

print(sol.countPairs([3,1,2,2,2,1,3], k = 2))
print(sol.countPairs([1,2,3,4] , 1))        