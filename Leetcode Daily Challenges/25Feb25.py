from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(arr)
        prefix = [[0] * 2 for _ in range(n)]
        currSum = 0 
        currOddSum = 0
        currEvenSum = 1 # cause currSum is 0 so it's an even number
        ans = 0
        
        for i in range(n):
            currSum += arr[i] # take the curr element
            if currSum % 2 == 1: # if current prefix sum is odd
                ans += currEvenSum # cause even + odd = odd sum
                currOddSum += 1
            else: # if currSum is even 
                ans += currOddSum # cause odd + even = odd sum
                currEvenSum += 1
            ans %= MOD
        return ans
    

sol = Solution()

arr = [1,3,5]
print(sol.numOfSubarrays(arr)) # 4

arr = [2,4,6]
print(sol.numOfSubarrays(arr)) # 0

arr = [1,2,3,4,5,6,7]
print(sol.numOfSubarrays(arr)) # 16