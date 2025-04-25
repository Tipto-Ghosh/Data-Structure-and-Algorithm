from typing import List
from collections import defaultdict
class Solution:
    def countInterestingSubarrays(self, arr: List[int], mod: int, k: int) -> int:
        """
        Count the number where element % mod == k --> call it prefix
        take a count_map where key = prefix % mod , val = count of key
        Now for every element in the array:
            if element % mod == K:
               prefix += 1
            target = (prefix - k + mod) - mod
            ans += count_map[target]
            Update count_map[prefix % mod] += 1 
        """
        count_map = defaultdict(int)
        count_map[0] = 1
        prefix , ans = 0 , 0
        
        for ele in arr:
            if ele % mod == k:
                prefix += 1
            target = (prefix - k + mod) % mod 
            ans += count_map[target]
            count_map[prefix % mod] += 1
        
        return ans   