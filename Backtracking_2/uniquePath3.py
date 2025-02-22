from typing import List
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        Rows , Cols = len(grid) , len(grid[0])
        directions = [(1,0) , (-1,0) , (0,1) , (0,-1)]
        totalNonObsCell = 0
        for row in range(Rows):
            for col in range(Cols):
                if grid[row][col] == 0:
                    totalNonObsCell += 1
                    
        def backtrack(row: int , col: int , vis: list[list[bool]] , countNonObsCell: int) -> int:
            # if row col is visited or obstacle then also there is no path
            if vis[row][col] or grid[row][col] == -1:
                return 0
            # if we are at a valid end position
            if grid[row][col] == 2:
                return 1 if countNonObsCell == totalNonObsCell else 0
            
            curr_path = 0
            vis[row][col] = True
            if grid[row][col] == 0:
                countNonObsCell += 1
            
            # try all possibilities
            for dr , dc in directions:
                nr , nc = row + dr , col + dc
                if 0 <= nr < Rows and 0 <= nc < Cols:
                    curr_path += backtrack(nr , nc , vis , countNonObsCell)
            
            vis[row][col] = False
            if grid[row][col] == 0:
                countNonObsCell -= 1
            return curr_path
        
        total_count = 0
        for row in range(Rows):
            for col in range(Cols):
                if grid[row][col] == 1:
                    vis = [[False] * Cols for _ in range(Rows)]
                    total_count = backtrack(row , col , vis , 0)
        return total_count
    

sol = Solution()
grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
print(sol.uniquePathsIII(grid))