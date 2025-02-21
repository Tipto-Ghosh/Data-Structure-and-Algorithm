from typing import List
class Solution:
    def maxCoins(self, arr: List[int]) -> int:
        n = len(arr)
        
        def solve(start: int , end: int) -> int:
            if start > end:
                return 0
            
            ans = 0
            for k in range(start , end + 1): # from start to end i can brust any balloon
                b1 = 1 if k == start else arr[k-1] # value of prev ballon
                b2 = arr[k]
                b3 = 1 if k == end else arr[k+1] # value of next ballon
                
                curr_ans = (b1 * b2 * b3) + solve(start , k-1) + solve(k+1 , end)
                ans = max(ans , curr_ans)
            return ans
        return solve(0 , n-1)

sol = Solution()
nums = [3,1,5,8]

print(sol.maxCoins(nums))