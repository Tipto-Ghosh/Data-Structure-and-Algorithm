from typing import List

class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans = []
        group = []
        
        for ch in s:
            group.append(ch)
            
            if len(group) == k:
                ans.append(''.join(group))
                group = []
        
        if len(group) > 0:
            while len(group) != k:
               group.append(fill)
            
            ans.append(''.join(group))
        
        return ans  

sol = Solution()

print(sol.divideString(s = "abcdefghi", k = 3, fill = "x"))
print(sol.divideString(s = "abcdefghij", k = 3, fill = "x"))   
# print(len("abcdefghij") % 3)    