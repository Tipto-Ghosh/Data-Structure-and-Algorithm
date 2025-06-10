from collections import defaultdict

class Solution:
    def maxDifference(self, s: str) -> int:
        """ 
        Find the max odd frequency of letter 
        Find the min even frequency of letter
        return the difference this two
        """
        
        freq_count = defaultdict(int)
        
        for letter in s:
            freq_count[letter] += 1
        
        # Find max odd and min even
        max_odd , min_even = 0 , float("INF")
        
        for count in freq_count.values():
            if count % 2 == 0:
                min_even = min(min_even , count)
            else:
                max_odd = max(max_odd , count)
        
        return max_odd - min_even


sol = Solution()

print(sol.maxDifference("aaaaabbc"))
print(sol.maxDifference("abcabcab"))