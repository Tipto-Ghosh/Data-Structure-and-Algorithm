from typing import List

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        """
        We have to all tops equal or all the bottoms equal
        So let's do it twice, first try to make tops euqal and then bottom
        If both possible then return the min one
        
        First try to make all top 1 and then 2 ...... till 6
        Take the min one to make 
        At any index we have 2 option
         -> if top is already equal to value then don't rotate
         -> If by doing rotate make the curr_val equal to value then do rotation and count 1
         -> If curr_val not euqal to value and also by doing rotation it's also not make it euqal to value then return INF
        
        Do the same thing also for the bottom values
        """
        
        n = len(tops)
        
        # changing parameters: value , index , top/bottom
        dp = {} # key = (value , index , pos) pos = 1 -> top , pos = 0 -> bottom
        
        def simulate(value: int , index: int , arr: List[int] , other: List[int] , pos: int) -> int:
            # Base case: If we are out of index then we are done
            if index >= n:
                return 0
            
            key = (value , index , pos)
            if key in dp:
                return dp[key]
            
            curr_count = 0
            # if current value is already equal to value then go to next index , no rotation needed
            if arr[index] == value:
               curr_count = simulate(value , index + 1 , arr , other , pos)
            elif other[index] == value:
                curr_count = 1 + simulate(value , index + 1 , arr , other , pos)
            else:
                curr_count = float('INF') 
            
            dp[key] = curr_count
            return curr_count
        
        
        final_count = float('INF')
        # For top part try 1 to 6
        for val in range(1 , 7):
            curr_count = simulate(val , 0 , tops , bottoms , 1)
            final_count = min(final_count , curr_count)
        # For bottom part try 1 to 6
        for val in range(1 , 7):
            curr_count = simulate(val , 0 , bottoms , tops , 0)
            final_count = min(final_count , curr_count)
        
        return final_count if final_count != float('INF') else -1
        

sol = Solution()

print(sol.minDominoRotations(tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]))  
print(sol.minDominoRotations(tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]))      