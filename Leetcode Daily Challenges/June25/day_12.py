from typing import List

class Solution:
    def maxAdjacentDistance(self, arr: List[int]) -> int:
        ans = 0
        n = len(arr)
        # from index 0 to n - 1
        for i in range(1 , n):
            diff = abs(arr[i] - arr[i-1])
            ans = max(ans , diff)
        
        # As it's circular so difference of first and last element
        diff = abs(arr[-1] - arr[0])
        ans = max(ans , diff)
        
        return ans 


sol = Solution()

print(sol.maxAdjacentDistance([1,2,4]))
print(sol.maxAdjacentDistance([-5,-10,-5]))