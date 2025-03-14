# Created By: Tipto Ghosh
# Creation Time: 2025/03/14 07:47:42


from typing import List
class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        # Minimum candies can get a child is 0 pile
        # Maximum candies can get a child is maxSize piles
        
        def tryToGive(curr_pile : int) -> bool:
            children_count = 0
            
            for pile in candies:
                if pile >= curr_pile:
                    # Count from the pile how many child can get curr_pile size candy
                    count = pile // curr_pile 
                    children_count += count
                    if children_count >= k:
                        return True
                    
            return False
        
        ans = 0
        maxPile = max(candies)
        l , r = 1 , maxPile
        while l <= r:
            mid = l + (r - l) // 2
            # we need a function that will tell us can we mid size pile to k childen or not
            canGive = tryToGive(mid)
            
            if canGive: 
                # If we can give mid_size piles then save it and try to give more larger size
                ans = mid 
                l = mid + 1
            else:
                r = mid - 1
        
        return ans 
     
        
sol = Solution()

candies = [5,8,6]
print(sol.maximumCandies(candies , 3))

candies = [2,5]
print(sol.maximumCandies(candies , 11))        