from typing import List
from collections import defaultdict
class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        ''' 
        Count the frequency of each element if any freq is odd then not possible return -1
        '''
        
        unique_vals = set() # store all the unique values from both basket
        freq1 = defaultdict(int)
        freq2 = defaultdict(int)
        
        for i in range(len(basket1)):
            freq1[basket1[i]] += 1
            freq2[basket2[i]] += 1
            
            unique_vals.add(basket1[i])
            unique_vals.add(basket2[i])
        
        swap_needed1 = []
        swap_needed2 = []
        
        for val in unique_vals:
            c1 , c2 = freq1[val] , freq2[val]
            
            if (c1 + c2) % 2 == 1:
                return -1
            
            diff = c1 - c2
            
            if diff > 0:
                swap_needed1.extend([val] * (diff // 2))
            elif diff < 0:
                swap_needed2.extend([val] * ((-1 * diff) // 2))
                
                
        
        
        swap_needed1.sort()
        swap_needed2.sort(reverse = True)
        min_val = min(min(basket1) , min(basket2))
        
        cost = 0
        for x , y in zip(swap_needed1 , swap_needed2):
            cost += min(min(x , y) , 2 * min_val)
        
        return cost      
    
sol = Solution()

# print(sol.minCost(basket1 = [4,2,2,2], basket2 = [1,4,1,2]))    
# print(sol.minCost(basket1 = [2,3,4,1], basket2 = [3,2,5,1])) 
# print(sol.minCost(basket1 = [4,1,3,2], basket2 = [3,4,1,2])) 

