from typing import List

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        """ 
        1. Exact Match: If the query matches a word in the wordlist exactly (case-sensitive), return that word.
        2. Case-Insensitive Match: If the query matches a word in the wordlist case-insensitively, return the first such match in the wordlist.
        3. Vowel Error Match: If the query matches a word in the wordlist by replacing all vowels ('a', 'e', 'i', 'o', 'u') with any vowel (case-insensitive), 
           return the first such match in the wordlist.
           
        Steps to implement:
        - Create a set for exact matches.
        - Create a dictionary for case-insensitive matches.
        - Create a dictionary for vowel error matches.
        """
        
        # for the vowel error => track just the freq of consonants of a word.
        vowels = set("aeiou")
        def devowel(word: str) -> str:
            # replace all vowels with *
            return "".join("*" if ch in vowels else ch for ch in word.lower())
        
        # 1. exact matches
        exact_matches_set = set(wordlist)
        
        # 2. Case-insensitive matches
        case_map = {}
        # 3. Vowel-error matches
        vowel_map = {}
        
        for word in wordlist:
            wordlow = word.lower()
            case_map.setdefault(wordlow, word)
            vowel_map.setdefault(devowel(wordlow), word)
        
        ans = []
        
        for query in queries:
            if query in exact_matches_set:
                ans.append(query)
            elif query.lower() in case_map:
                ans.append(case_map[query.lower()])
            elif devowel(query.lower()) in vowel_map:
                ans.append(vowel_map[devowel(query)])
            else:
                ans.append("")
        
        return ans  
    
sol = Solution()

print(sol.spellchecker(
    wordlist=["KiTe","kite","hare","Hare"],
    queries=["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
))
print(sol.spellchecker(wordlist = ["yellow"], queries = ["YellOw"]))