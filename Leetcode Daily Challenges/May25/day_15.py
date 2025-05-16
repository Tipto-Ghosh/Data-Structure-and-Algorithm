from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        """
        we have 2 groups one is words and another is a binary array(0/1)
        each word in words are associated with a binat number. 0 or 1
        if can take the word if it's adjacent has the opposite number 
        """
        
        ans = []
        prev_num = -1
        
        for i in range(n):
            if groups[i] != prev_num:
                ans.append(words[i])
                prev_num = groups[i]
        
        return ans     
            