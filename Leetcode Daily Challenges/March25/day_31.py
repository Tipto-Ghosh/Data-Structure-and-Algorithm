from typing import List

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        total_pairs = n - 1
        pairSum = [] 
        
        for i in range(1 , n):
            pairSum.append(weights[i] + weights[i-1])
            
        
        pairSum.sort()
        # Max sum = sum of last k element
        maxCost = 0
        minCost = 0 # sum of First k elements
        for i in range(k - 1):
            minCost += pairSum[i]
            maxCost += pairSum[total_pairs - 1 - i]
        
        return maxCost - minCost

sol = Solution()

print(sol.putMarbles([1,3,5,1] , 2))
print(sol.putMarbles([1,3] , 2))        