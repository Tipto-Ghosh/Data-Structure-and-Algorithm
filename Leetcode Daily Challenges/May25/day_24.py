from typing import List

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        ans = []
        
        for index , word in enumerate(words):
            if x in word:
                ans.append(index)
            
        return ans 
    
sol = Solution()
print(sol.findWordsContaining(words = ["leet","code"], x = "e"))
print(sol.findWordsContaining(words = ["abc","bcd","aaaa","cbc"], x = "a"))
print(sol.findWordsContaining(words = ["abc","bcd","aaaa","cbc"], x = "z"))