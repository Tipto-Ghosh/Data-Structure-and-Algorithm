from typing import List

class Solution:
    def minSum(self, arr1: List[int], arr2: List[int]) -> int:
        """
        Find the sum of arrays
        As we need to make element > 0 and also sum need to be min and equal so replace all 0's with 1 first
        Find the number of 0's in both arrays
        min_sum will be sum1 + zero1 and sum2 + zero2
        
        - If there is at leat 1 zero in both array solution always exists
        at this case ans will be max(sum1 + zero1 and sum2 + zero2)
        
        If there is no zero in any arrays then
          if boths sum is not equal ans is sum
          else no solution exists
        """

        sum1 , sum2 = 0 , 0
        
        count_zero1 , count_zero2 = 0 , 0
        
        # Find sum of arr1 and also replace 0
        for ele in arr1:
            if ele == 0:
                sum1 += 1 # Add 1
                count_zero1 += 1
            else:
                sum1 += ele # add current element
                
        # Find sum of arr1 and also replace 0
        for ele in arr2:
            if ele == 0:
                sum2 += 1 # Add 1
                count_zero2 += 1
            else:
                sum2 += ele # add current element
        
        if (count_zero1 == 0 and sum2 > sum1):
            # we need to increase sum1 but there is no zero that we can replace to increase the sum so no ans possible
            return -1
        if (count_zero2 == 0 and sum1 > sum2):
            # we need to increase sum2 but there is no zero that we can replace to increase the sum so no ans possible
            return -1
         
        # if any one has at least one 0
        return max(sum1 , sum2)
        
        
sol = Solution()

print(sol.minSum([3,2,0,1,0] , [6,5,0]))
print(sol.minSum([2,0,2,0] , [1,4]))