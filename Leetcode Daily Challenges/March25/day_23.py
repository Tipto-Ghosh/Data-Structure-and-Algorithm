from typing import List
from collections import defaultdict
import heapq
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        mod = (10 ** 9) + 7
        # Step-1: Make the adjacency List
        # Step-2: Apply Dijkstra and Find distance from Src(0) to to target(n-1) node
        # Step-3:
        
        adjList = defaultdict(list)
        for u , v , time in roads:
            adjList[u].append((v , time))
            adjList[v].append((u , time))
        
        # Doing Dijstra To Find the shortest Path
        distance = [float('inf')] * n 
        ways = [0] * n # store ways to go i to n-1
        min_heap = [(0 , 0)] # (distance , node)
        distance[0] = 0 # src to src distance is 0
        ways[0] = 1 # As per question there is at least one path
        
        while min_heap:
            node_time , node = heapq.heappop(min_heap)
            
            # If going through curr_node take more time then skip it
            if node_time > distance[node]:
                continue
            
            # Traverse all neighbours
            for neiNode , neiNodeTime in adjList[node]:
                new_time = node_time + neiNodeTime
                
                # If we got a shortest path
                if new_time < distance[neiNode]:
                    distance[neiNode] = new_time
                    ways[neiNode] = ways[node]
                    heapq.heappush(min_heap , (new_time , neiNode))
                elif new_time == distance[neiNode]:
                    ways[neiNode] = (ways[neiNode] + ways[node]) % mod 
        
        return ways[n-1]
                
        
sol = Solution()

print(sol.countPaths(7 , [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]))

print(sol.countPaths(2 , [[1,0,10]]))        