from typing import List
from collections import deque
import heapq
class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        # Brute Force:
        """
        For every number in the query apply BFS and find the point 
        """
        # Optimization Part:
        """
        1. I Can store the point for each queries so that if there is repeatation of value in queries
        then we will calculate once
        2. If we have calculated for X and we get a number Y which is greater X then we can it is sure that
           we will get the point for Y = point_of_X + Some_more_maybe
        """
        """
        directions = [(1 , 0) , (-1 , 0) , (0 , 1) , (0 , -1)]
        Rows , Cols = len(grid) , len(grid[0])
        queries_map = {}
        
        def BFS(val: int) -> int:
            if grid[0][0] >= val:
                return 0
            
            vis = set()
            point = 0 
            q = deque([(0 , 0)])
            
            while q:
                r , c = q.popleft()
                
                # if curr position is not visited before then take the point and visit it
                if val > grid[r][c] and (r , c) not in vis:
                    # Take the point and mark as visited
                    point += 1
                    vis.add((r , c))
                    # Now explore it's neighnours
                    for dr , dc in directions:
                        nr , nc = r + dr , c + dc 
                        if (0 <= nr < Rows) and (0 <= nc < Cols):
                            q.append((nr , nc))
                            
            
            return point    
                
                
        ans = []
        for val in queries:
            # ans.append(BFS(val))
            if val not in queries_map:
               point = BFS(val)
               queries_map[val] = point
            # if we calculated before then just take the ans
            ans.append(queries_map[val])
            
        return ans 
        """
        
        # Starting the Optimized Part
        Rows , Cols = len(grid) , len(grid[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        ans = [0] * len(queries)
        # Sort the queries but track the original index
        sorted_queries = sorted(enumerate(queries) , key = lambda x: x[1])
        # Use a min-heap to access the cells in increasing order based on cell value
        minHeap = [(grid[0][0] , 0 , 0)] # (value , row , col)
        vis = set()
        vis.add((0 , 0))
        points = 0 
        
        for index , value in sorted_queries:
            # Calculated the point for current value
            # If we already calculated a value less than current value then start from where we end before
            while minHeap and minHeap[0][0] < value:
                cell_value , r , c = heapq.heappop(minHeap)
                # We are at a cell which we dont visit before and also cell_val < value so take the point
                points += 1
                
                # Explore curr cell's neighbours
                for dr , dc in directions:
                    nr , nc = r + dr , c + dc 
                    if 0 <= nr < Rows and 0 <= nc < Cols and (nr , nc) not in vis:
                        heapq.heappush(minHeap , (grid[nr][nc] , nr , nc))
                        vis.add((nr , nc))
            
            # As we calculated for the current value store the ans
            ans[index] = points 
        
        return ans 
        
        

sol = Solution()

print(sol.maxPoints(grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]))
print(sol.maxPoints(grid = [[5,2,1],[1,1,2]], queries = [3]))

# min_heap = [6,1,8,9,3,4]
# heapq.heapify(min_heap)
# print(min_heap)