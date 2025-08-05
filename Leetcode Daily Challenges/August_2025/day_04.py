from typing import List
from collections import defaultdict
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        
        """ 
        We have to find the largest subarray with 2 unique values.
        
        Steps:
          1. initialize left and right
          2. move the right pointer forward
          3. if any third unique value comes then stop
          4. start moving the left pointer till we again have 2 unique
          5. in between we have to track the max length of the window for answer.
        """
        left = 0
        busket = defaultdict(int)
        ans = 0
        
        for right in range(len(fruits)):
            # take the current fruit
            busket[fruits[right]] += 1
            
            # if rules violoate
            while len(busket) > 2:
                # start shrinking
                busket[fruits[left]] -= 1
                if busket[fruits[left]] == 0:
                   busket.pop(fruits[left])
                left += 1
            
            # take the ans
            ans = max(ans , right - left + 1)
        
        return ans 
            

sol = Solution()

print(sol.totalFruit([1,2,1]))
print(sol.totalFruit([0,1,2,2]))
print(sol.totalFruit([1,2,3,2,2]))             