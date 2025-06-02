from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        
        """ 
        First pass (left to right):
            If ratings[i] > ratings[i - 1], then candies[i] = candies[i - 1] + 1.

        Second pass (right to left):
            If ratings[i] > ratings[i + 1], then
        
        candies[i] = max(candies[i], candies[i + 1] + 1).
        """
        
        candies = [1] * n # each child must have at least 1 candy
        
        # left to right
        for i in range(1 , n):
            # if curr child rating is greater than prev then give curr_child 1 more candy than prev_child
            if ratings[i] > ratings[i-1]:
                candies[i] = 1 + candies[i-1]
        
        # right to left 
        for i in range(n - 2 , -1 , -1):
            # if curr child rating is greater than next then give curr_child 1 more candy than next_child
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i] , 1 + candies[i + 1])
        
        return sum(candies)        
     
            
sol = Solution()

print(sol.candy([1,0,2]))
print(sol.candy([1,2,2]))