from typing import List

class Solution:
    def maxAbsoluteSum(self, arr: List[int]) -> int:
        n = len(arr)
        positivePrefixSum = [0]
        negativePrefixSum = [0]
        
        # So after taking an element
           # For +ve sum array we have a choice of max(positivePrefixSum[i-1] + arr[i] , 0)
           # For -ve sum array we have a choice of min(negativePrefixSum[i-1] + arr[i] , 0)
        # And also track the indiviual 1 length array sum
        ans = 0
        
        for i in range(n):
            # taking the indiviual absolute max element
            ans = max(ans , abs(arr[i]))
            # make the positive prefix sum
            currPosSum = max(0 , positivePrefixSum[-1] + arr[i])
            positivePrefixSum.append(currPosSum)
            # make the negative prefix sum
            currNegSum = min(0 , negativePrefixSum[-1] + arr[i])
            negativePrefixSum.append(currNegSum)
        
        # Find the max element from the positivePrefixSum
        maxSum = max(positivePrefixSum)
        # Find the min element from the negativePrefixSum
        minSum = min(negativePrefixSum)    
        # So the final answer will be the absolute of any sub-array     
        return max(ans , maxSum , abs(minSum))
        
        
        
sol = Solution()

nums = [1,-3,2,3,-4]
print(sol.maxAbsoluteSum(nums))        
        
nums = [2,-5,1,-4,3,-2]
print(sol.maxAbsoluteSum(nums))        