from typing import List 

class Solution:
    def buildArray(self, arr: List[int]) -> List[int]:
        # Length of the array
        n = len(arr)
        # length of the answer array will be same
        ans = [0 for _ in range(n)]
        
        # ans[i] = arr[arr[i]]
        
        for i in range(n):
            ans[i] = arr[arr[i]]
        
        return ans 

sol = Solution()

print(sol.buildArray([0,2,1,5,3,4]))
print(sol.buildArray([5,0,1,2,3,4]))