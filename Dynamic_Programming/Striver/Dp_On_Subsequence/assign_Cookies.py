from typing import List
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        len_g = len(g)
        len_s = len(s)
        count = 0
        i , j = 0 , 0
        while i <  len_g:
            while j < len_s and s[j] < g[i]:
                j += 1
            if j >= len_s:
                break
            count += 1
            i += 1
            j += 1
        return count
    
sol = Solution()
g = [1,2]
s = [1,2,3]

print(sol.findContentChildren(g , s))    