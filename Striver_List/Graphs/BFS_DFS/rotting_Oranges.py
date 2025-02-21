from typing import List
from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        count_fresh_orange = 0
        rotten_oranges = []
        
        ROWS , COLS = len(grid) , len(grid[0])
        
        for row in range(ROWS):
            for col in range(COLS):
                if grid[row][col] == 1:
                    count_fresh_orange += 1
                elif grid[row][col] == 2:
                    rotten_oranges.append((row , col , 0)) # row , col , rotten_time
        
        direct = [[0 , 1] , [0 , -1] , [1 , 0] , [-1 , 0]]
        time = 0
        q = deque(rotten_oranges)
        while q:
            row , col , curr_time = q.popleft()
            time = max(time , curr_time)
            for dr , dc in direct:
                r = row + dr
                c = col + dc
                
                if 0 <= r < ROWS and 0 <= c < COLS and grid[r][c] == 1:
                    count_fresh_orange -= 1
                    q.append((r , c , 1 + curr_time))
                    grid[r][c] = 2
        
        return time if count_fresh_orange == 0 else -1