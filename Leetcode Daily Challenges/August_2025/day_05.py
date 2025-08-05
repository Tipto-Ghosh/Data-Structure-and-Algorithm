from typing import List

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        
        for i in range(n):
            curr_fruit = fruits[i]
            
            for j in range(n):
                if curr_fruit <= baskets[j]:
                    baskets[j] = 0
                    break
        
        count = 0
        for ele in baskets:
            if ele != 0:
                count += 1
        
        return count


sol = Solution()

print(sol.numOfUnplacedFruits(fruits = [4,2,5], baskets = [3,5,4]))
print(sol.numOfUnplacedFruits(fruits = [3,6,1], baskets = [6,4,7]))