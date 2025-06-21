from collections import Counter

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        freq = Counter(word)
        
        # Take the frequency values
        freq_values = list(freq.values())
        # Unique frequency
        unique_freq = set(freq_values)
        
        min_remove = float('inf')
        
        for base in unique_freq:
            deletions = 0
            
            for f in freq_values:
                if f < base:
                    # remove entire part
                    deletions += f 
                elif f > base + k: 
                    deletions += (f - (base + k))
            
            min_remove = min(min_remove , deletions)
        
        return min_remove        


sol = Solution()
print(sol.minimumDeletions(word = "aabcaba", k = 0))    # 3  
print(sol.minimumDeletions(word = "dabdcbdcdcd", k = 2)) # 2
print(sol.minimumDeletions( word = "aaabaaa", k = 2)) # 1
print(sol.minimumDeletions("aaabbbbbbwwwwww" , 2)) # 2