from typing import List

class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        # split the letters of brokenLetters
        brokenLetters = set(ch for ch in brokenLetters)
        
        # split the words of text
        words = text.split(" ")
        count = 0
        # now if a words a letter that contains brokenLetters then this word we can't type
        for word in words:
            isPossible = True 
            for ch in word:
                if ch in brokenLetters:
                    isPossible = False 
                    break
            
            if isPossible:
               count += 1
        
        return count


sol = Solution()

print(sol.canBeTypedWords(text = "hello world", brokenLetters = "ad")) 
print(sol.canBeTypedWords(text = "leet code", brokenLetters = "lt"))
print(sol.canBeTypedWords(text = "leet code", brokenLetters = "e"))