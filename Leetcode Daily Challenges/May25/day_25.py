from typing import List
from collections import Counter

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        count = Counter(words)
        length = 0
        # used_center = False

        for word in list(count.keys()):
            rev = word[::-1]
            if word == rev:
                # even number of same palindromic words can form complete pairs
                pairs = count[word] // 2
                length += pairs * 4 # every word has 2 len and pair_len = pair * 2
                count[word] -= pairs * 2
            elif rev in count:
                # take min of word and its reverse
                pairs = min(count[word], count[rev])
                length += pairs * 4
                count[word] -= pairs
                count[rev] -= pairs

        # now check if we can put a palindromic word in the middle
        for word in count:
            if word[0] == word[1] and count[word] > 0:
                length += 2
                break

        return length

sol = Solution()
print(sol.longestPalindrome(["lc","cl","gg"]))              # Output: 6
print(sol.longestPalindrome(["ab","ty","yt","lc","cl","ab"])) # Output: 8
print(sol.longestPalindrome(["cc","ll","xx"]))              # Output: 6
