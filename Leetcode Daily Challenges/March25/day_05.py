from collections import deque
class Solution:
    def coloredCells(self, n: int) -> int:
        # ----------------------THIS A VALID SOLUTION BUT AS CONSTRAINTS IS HIGHT THIS WILL GIVE MEMORY LIMIT EXCEEDED----------------
        # Start from cell (0,0)
        # At every minute take all the 4 neighbor cells if there are not taken
        """""
        directiions = [(0,1) , (0,-1) , (1,0) , (-1,0)]
        visited = set() # Track the visited positions
        queue = deque([(0 , 0)]) # start from position [0,0]
        visited.add((0 , 0))
        
        count_colored_cells = 0
        curr_minute = 0
        
        while queue:
            level_size = len(queue) # Number of cells we need to proccess for current minute
            for _ in range(level_size):
                row , col = queue.popleft()
                count_colored_cells += 1
                
                # Take all the neighbors
                for dr , dc in directiions:
                    nr , nc = row + dr , col + dc
                    if (nr , nc) not in visited:
                        visited.add((nr , nc))
                        queue.append((nr , nc))
            
            # we are done with current level
            curr_minute += 1
            if curr_minute == n:
                break 
        
        return count_colored_cells
        """
        # This is math problem
        return (n * n) + (n-1) * (n-1)
        
        
sol = Solution()

print(sol.coloredCells(1))
print(sol.coloredCells(2))
print(sol.coloredCells(3))        