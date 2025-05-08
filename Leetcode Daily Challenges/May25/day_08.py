from typing import List
import heapq

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        Rows , Cols = len(moveTime) , len(moveTime[0])
        infinity = float('inf')
        directions = [(1 , 0) , (-1 , 0) , (0 , 1) , (0 , -1)]
        
        """
        1. starting time 0 and starting position is (0 , 0)
        2. adjacent cell: left , right , up , down
        3. moving to adjacent cell extra 1 second for odd move and 2 second for even move
           Ex: 1st move = 1s , 2nd move = 2s , 3rd move = 1s , 4th move = 2s
           Note: Track the move count also
        """
        
        src = (0 , 0 , 0 , 0) # starting pos(0 , 0) , time = 0 and move = 0
        
        # track the visited cells
        visited = [[False] * Cols for _ in range(Rows)]
        
        # track the min time also
        minimum_times = [[infinity] * Cols for _ in range(Rows)] # track min_time to reach each cell from 0,0
        min_heap = []
        
        # src to src time needed 0
        minimum_times[0][0] = 0
        heapq.heappush(min_heap , src)
        
        while min_heap:
            t , move_count , row , col = heapq.heappop(min_heap)
            
            # if current cell is visited so skip it
            if visited[row][col]:
                continue
            
            # visit the current cell
            visited[row][col] = True
            
            # Go to every adjacent cell
            for dr , dc in directions:
                nr , nc = row + dr , col + dc 
                
                # if not a valid cell then skip
                if not (0 <= nr < Rows and 0 <= nc < Cols):
                    continue
                
                # Find the move_time needed
                extra_time = 1 if move_count % 2 == 0 else 2
                # Find the curr_time needed
                curr_time = max(minimum_times[row][col] , moveTime[nr][nc]) + extra_time
                
                if curr_time < minimum_times[nr][nc]:
                    minimum_times[nr][nc] = curr_time
                    heapq.heappush(min_heap , (curr_time , move_count + 1 , nr , nc))
        
        return minimum_times[Rows - 1][Cols - 1]
                        

sol = Solution()

print(sol.minTimeToReach([[0,4],[4,4]]))       
print(sol.minTimeToReach([[0,0,0,0],[0,0,0,0]])) 