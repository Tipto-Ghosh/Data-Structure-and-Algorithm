# Created By: Tipto Ghosh
# Creation Time: 2025/03/16 06:29:27


from typing import List
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        # Take a minutes range 
        # Then in this range always pick the mid-minute and count how many car's can be repaired in this time
        # If we can repair in this mid_min then try to minimize it more
        # Else try for more bigger minutes
        
        def repairInMidTime(curr_time: int) -> bool:
            count_cars = 0
            for r in ranks:
                n = int((curr_time / r) ** 0.5)
                count_cars += n 
                if count_cars >= cars:
                    return True
            
            return count_cars >= cars 
        
        # Make min_time possible
        max_time = cars * cars * max(ranks)
        min_time = max_time
        s , e = 0 , max_time
        
        while s <= e:
            mid_time = s + (e - s) // 2
            
            can_do = repairInMidTime(mid_time)
            
            if can_do:
                min_time = mid_time
                e = mid_time - 1
            else:
                s = mid_time + 1
        
        return min_time
        
        
sol = Solution()        

print(sol.repairCars([4,2,3,1] , 10))

print(sol.repairCars([5,1,8] , 6))        