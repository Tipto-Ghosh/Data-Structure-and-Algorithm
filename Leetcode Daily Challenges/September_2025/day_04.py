class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        """
        Determines which of the two numbers (x or y) is closer to a third number (z).
        
        Args:
            x (int): First number.
            y (int): Second number.
            z (int): Reference number to compare distances.
        
        Returns:
            int: Returns 1 if x is closer to z, 2 if y is closer to z, and 0 if both are equally close.
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