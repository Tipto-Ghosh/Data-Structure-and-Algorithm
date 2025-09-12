from collections import defaultdict

class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}
        
        # collect vowels from s
        vowel_list = [ch for ch in s if ch in vowels]
        
        # sort vowels by ASCII
        vowel_list.sort(key=lambda x: ord(x))
        
        # rebuild string
        result = []
        j = 0
        for ch in s:
            if ch in vowels:
                result.append(vowel_list[j])
                j += 1
            else:
                result.append(ch)
        
        return ''.join(result)


sol = Solution()
print(sol.sortVowels("lEetcOde"))  # "lEOtcede"
print(sol.sortVowels("lYmpH"))     # "lYmpH"
