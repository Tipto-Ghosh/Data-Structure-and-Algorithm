from collections import defaultdict
class Solution:
    def _isVowel(self , c: str) -> bool:
            return c in ['a' , 'e' , 'i' , 'o' , 'u']
        
    def _atLeastK(self , word: str , k: int) -> int:
        num_valid_substr = 0
        start , end = 0 , 0
        # Track count vowels and consonants
        vowel_count = {}
        consonant_count = 0
        
        while end < len(word):
            # If letter is vowel
            if self._isVowel(word[end]):
                vowel_count[word[end]] = vowel_count.get(word[end] , 0) + 1
            else:
                consonant_count += 1
            
            while len(vowel_count) == 5 and consonant_count >= k:
                num_valid_substr += len(word) - end 
                start_letter = word[start]
                if self._isVowel(start_letter):
                    vowel_count[start_letter] = vowel_count.get(start_letter) - 1
                    if vowel_count.get(start_letter) == 0:
                        vowel_count.pop(start_letter)
                else:
                    consonant_count -= 1
                start += 1
            
            end += 1
        return num_valid_substr
    
    
    def countOfSubstrings(self, word: str, k: int) -> int:
        return self._atLeastK(word , k) - self._atLeastK(word , k + 1)
            
                            
sol = Solution()

print(sol.countOfSubstrings('aeioqq' , 1))

print(sol.countOfSubstrings('aeiou' , 0))

print(sol.countOfSubstrings('ieaouqqieaouqq' , 1))