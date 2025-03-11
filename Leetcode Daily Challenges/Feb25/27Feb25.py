from typing import List
from collections import defaultdict
class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        index_map = {val : index for index , val in enumerate(arr)}
        dp = [[-1] * n for _ in range(n)]
        
        def solve(start , end) -> int:
            if dp[start][end] != -1:
                return dp[start][end]
            
            # find the previous fibonacci element of start_indx
            prevFiboEle = arr[end] - arr[start]
            currFiboLen = 0
            
            if prevFiboEle in index_map and index_map[prevFiboEle] < start:
                prevIndex = index_map[prevFiboEle]
                currFiboLen = 1 + solve(prevIndex , start) 
                
            dp[start][end] = currFiboLen
            return currFiboLen
            
            
        # start from any index
        ans = 0
        for start in range(n):
            for end in range(start + 1 , n):
                currMaxLen = 2 + solve(start , end)
                ans = max(ans , currMaxLen)
        
        return ans if ans >= 3 else 0


sol = Solution()
arr = [1,2,3,4,5,6,7,8]
print(sol.lenLongestFibSubseq(arr))

arr = [1,3,7,11,12,14,18]
print(sol.lenLongestFibSubseq(arr))