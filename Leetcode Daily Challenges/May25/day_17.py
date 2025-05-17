from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        As we need to sort in place and we can use any built-in function and extra space
        so we can just simple count the colors(there can be only 3 types of colors: 0,1,2)
        then we can put 0 first and then 1 and then 2
        """
        count_zero , count_one , count_two = 0 , 0 , 0
        
        for ele in nums:
            if ele == 0:
                count_zero += 1
            elif ele == 1:
                count_one += 1
            else:
                count_two += 1
        
        # put all the zero first
        index = 0
        for i in range(count_zero):
            nums[index] = 0
            index += 1
        
        # put all the one's
        for i in range(count_one):
            nums[index] = 1
            index += 1
        
        # put all the two's
        for i in range(count_two):
            nums[index] = 2
            index += 1
        
            
sol = Solution()

nums = [2,0,2,1,1,0]
sol.sortColors(nums)
print(nums)        