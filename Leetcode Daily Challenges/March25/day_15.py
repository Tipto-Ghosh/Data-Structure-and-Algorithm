from typing import List
class Solution:
    def minCapability(self, arr: List[int], k: int) -> int:
        # It's question like find the minimun of the maximum.
        # For this type of question we binary search.
        # First we have to find the range
        # So for any value of k we will able to the min_value amount of cash. Lower_bound = minValue from arr 
        # Now upper bound: we can take at most the maxElemnt for k = 1 and for any other value of k we need to take the less then this amount
        n = len(arr)
        def can_rob_k_houses(capability: int) ->bool:
            count_house = 0
            i = 0
            while i < n and capability > 0:
                # if curr_cash <= capability then rob the house.
                # if we rob then count will increse and skip the next house
                if arr[i] <= capability:
                    i += 2
                    count_house += 1
                    if count_house == k:
                        return True
                else:
                    i += 1
            return count_house >= k 
        
        low , high = min(arr) , max(arr)
        min_capability = high
        while low <= high:
            curr_capability = low + (high - low) // 2
            # Make a function with this capability can we rob at least k house?
            is_possible = can_rob_k_houses(curr_capability)
             
            if is_possible:
               # If we can then take it and try to min the capability
               min_capability = min(min_capability , curr_capability)
               high = curr_capability - 1
            else: # curr_capability is not enough for robbing at least k house.We need more
                low = curr_capability + 1
        
        return min_capability    

sol = Solution()

nums = [2,3,5,9]   
print(sol.minCapability(nums , 2))

nums = [2,7,9,3,1]
print(sol.minCapability(nums , 2))
         