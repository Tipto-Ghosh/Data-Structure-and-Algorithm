from typing import List

class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        """ 
        Diagonal = sqrt(length**2 + width**2)
        Area = length * width
        """
        longest_diagonal = 0
        max_area = 0
        
        for length , width in dimensions:
            # print(f"length: {length} , width: {width}")
            diagonal = (length**2 + width**2) ** 0.5
            area = length * width
            
            if diagonal > longest_diagonal:       
              #print(f"diagonal: {diagonal} , longest_diagonal:{longest_diagonal} , max_area: {max_area} , area: {area}")
               longest_diagonal = diagonal
               max_area =  area
            elif diagonal == longest_diagonal:
                max_area = max(max_area , area)
        
        return max_area

sol = Solution()
print(sol.areaOfMaxDiagonal([[9,3],[8,6]]))
print(sol.areaOfMaxDiagonal([[6,5],[8,6],[2,10],[8,1],[9,2],[3,5],[3,5]]))