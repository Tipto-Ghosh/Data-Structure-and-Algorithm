from typing import List
from collections import defaultdict

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = defaultdict(int) 
        max_freq = 0
        
        for num in nums:        
            freq[num] += 1
            max_freq = max(max_freq , freq[num])
        
        count = 0
        for _ , f in freq.items():
            if f == max_freq:
                count += f 
        
        return count 
    
sol = Solution()
print(sol.maxFrequencyElements([1,2,2,3,1,4]))        