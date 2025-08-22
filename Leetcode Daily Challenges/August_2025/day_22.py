from typing import List

class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        
        rows , cols = len(grid) , len(grid[0])
        
        min_i , max_i = rows , 0
        min_j , max_j = cols , 0
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    min_i = min(min_i , i)
                    min_j = min(j , min_j)
                    
                    max_i = max(max_i , i)
                    max_j = max(max_j , j) 
        
        return (max_i - min_i + 1) * (max_j - min_j + 1)
        