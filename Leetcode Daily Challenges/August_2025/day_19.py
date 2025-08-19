from typing import List

class Solution:
    def zeroFilledSubarray(self, arr: List[int]) -> int:
        """ 
        For n elements there can be total = n * (n + 1) / 2 sub-arrays
        so always count the number of consicuitive number of 0's 
        """
        count_sub_arr = 0
        count_zeros = 0
        
        for element in arr:
            if element != 0:
               count_sub_arr += (count_zeros * (count_zeros + 1) // 2)
               count_zeros = 0
            else:
                count_zeros += 1
        
        # for the last sub-array
        count_sub_arr += (count_zeros * (count_zeros + 1) // 2)
        return count_sub_arr

sol = Solution()         

print(sol.zeroFilledSubarray([1,3,0,0,2,0,0,4]))
print(sol.zeroFilledSubarray([0,0,0,2,0,0]))
print(sol.zeroFilledSubarray([2,10,2019]))        