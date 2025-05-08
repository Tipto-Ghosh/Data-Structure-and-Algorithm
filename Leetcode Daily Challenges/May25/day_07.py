import heapq

class Solution:
    def minTimeToReach(self, moveTime):
        """
        1. Starting time = 0s and position is [0,0]
        2. Moving from a to b we need max(time_a , time_b) + 1
        3. Only we can move to left , right , up and down
        
        We need to find the shortest time from (0 , 0) to (rows-1 , cols - 1)
        we will use shortest path to find the min time
        """
        infinity = float('inf')
        directions = [(1 , 0) , (-1 , 0) , (0 , 1) , (0 , -1)]
        
        Rows , Cols = len(moveTime) , len(moveTime[0])
        
        # source
        src = (0 , 0 , 0) # position [0 , 0] and src to src time 0
        min_heap = []
        
        heapq.heappush(min_heap , src)
        
        visited = [[False] * Cols for _ in range(Rows)] # track the visited cells
        # also make a dist list which store the shorted time from [0,0] to every cell
        distance = [[infinity] * Cols for _ in range(Rows)] # initially all distance/time is inifinity
        # src to src time is 0
        distance[0][0] = 0
        
        while min_heap:
            # take the cell
            time , r , c = heapq.heappop(min_heap)
            
            # if currenct cell is visited then don't need to revisit , skip it
            if visited[r][c]:
                continue
            
            # So make it visited
            visited[r][c] = True
            
            # otherwise take the current cell and move to it's adjacent cells
            for dr , dc in directions:
                nr , nc = r + dr , c + dc 
                # If not a valid cell then skip
                if not (0 <= nr < Rows and 0 <= nc < Cols):
                    continue
                # find the time
                time_needed = 1 + max(distance[r][c] , moveTime[nr][nc])
                # if we got a smaller time than current time then update
                if time_needed < distance[nr][nc]:
                    distance[nr][nc] = time_needed
                    heapq.heappush(min_heap , (time_needed , nr , nc))
                
            
        return distance[Rows - 1][Cols - 1]
        
sol = Solution()

print(sol.minTimeToReach([[0,4],[4,4]]))        