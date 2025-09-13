from collections import defaultdict
class Solution:
    def maxFreqSum(self, s: str) -> int:
        # https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/?envType=daily-question&envId=2025-09-13
        
        vowels = {'a' , 'e' , 'i' , 'o' , 'u'}
        
        vowels_freq = defaultdict(int)
        consonant_freq = defaultdict(int)
        
        for ch in s:
            if ch in vowels:
                vowels_freq[ch] += 1
            else:
                consonant_freq[ch] += 1
        
        max_vowel_freq , max_consonant_freq = 0 , 0
        
        for _ , freq in vowels_freq.items():
            max_vowel_freq = max(max_vowel_freq , freq)
        
        for _ , freq in consonant_freq.items():
            max_consonant_freq = max(max_consonant_freq , freq)
        
        return max_vowel_freq + max_consonant_freq
     
sol = Solution()
print(sol.maxFreqSum("successes"))
print(sol.maxFreqSum("aeiaeia"))        