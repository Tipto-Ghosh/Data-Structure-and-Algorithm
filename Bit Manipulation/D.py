from typing import List
class Solution:
    def maximumStrongPairXor(self, arr: List[int]) -> int:
        ans = - float('inf')
        strong_pairs = set()
        n = len(arr)
        for i in range(n):
            for j in range(i + 1 , n):
                if abs(arr[i] - arr[j]) <= min(arr[i] , arr[j]):
                   xor = arr[i] ^ arr[j] 
                   ans = max(ans , xor)          
         
        return ans