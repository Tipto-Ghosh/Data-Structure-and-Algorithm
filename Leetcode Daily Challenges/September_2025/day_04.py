class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        """ 
        Find the distance of both x and y from z.
        And say which distance is lowest. 
        """
        dis_x = abs(x - z)
        dis_y = abs(y - z)
        
        if dis_x < dis_y:
            return 1
        elif dis_x > dis_y:
            return 2
        else:
            return 0

sol = Solution()

print(sol.findClosest(2 , 7 , 4))