from typing import List
from collections import defaultdict
class Solution:
    def countGood(self, arr: List[int], k: int) -> int:
        n = len(arr)
        track_count = defaultdict(int)
        left , right  = 0 , 0
        pairs = 0
        ans = 0
        
        while right < n:
            pairs += track_count[arr[right]] 
            track_count[arr[right]] += 1
            
            while pairs >= k:
                ans += (n - right)
                track_count[arr[left]] -= 1
                pairs -= track_count[arr[left]]
                left += 1
            
            right += 1
        
        return ans      
        
        
sol = Solution()
print(sol.countGood([1,1,1,1,1], k = 10))        