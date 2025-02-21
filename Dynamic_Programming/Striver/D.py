from typing import List
class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        count = 0
        
        for i in range(len(words)):
            w1 = words[i]
            for j in range(i + 1 , len(words)):
                w2 = words[j]
                is_prefix = w1 == w2[ : len(w1)]
                is_suffix = w1 == w2[-len(w1) : ]
                if is_prefix and is_suffix:
                    count += 1 
                
                
        return count