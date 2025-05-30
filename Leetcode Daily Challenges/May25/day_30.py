from typing import List
from collections import deque
import heapq
class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        """ 
        1. Make the adjList
        2. Find the distance of all nodes from node1 and node2 by applying. X[bfs cause unweighted directed graph]
        3. Sort the distance array and apply binary search to find the minimum reachable node
        """
        inf = float('INF')
        n = len(edges)
        # make the adjList
        adjList = [[] for _ in range(n)]
        
        for u in range(n):
            v = edges[u]
            if v != -1: # cause -1 means no outgoing edge
                adjList[u].append((v , 1))
            
        def shortest_path(src: int) -> List[int]:
            distance = [inf for _ in range(n)]
            
            # src to src distance is 0
            distance[src] = 0
            
            min_heap = [] 
            heapq.heappush(min_heap , (0 , src)) # (distance , node)
            
            while min_heap:
                node_dist , node = heapq.heappop(min_heap)
                
                for neiNode , neiNodeDistance in adjList[node]:
                    if distance[neiNode] > node_dist + neiNodeDistance:
                        distance[neiNode] = node_dist + neiNodeDistance
                        heapq.heappush(min_heap , (distance[neiNode] , neiNode))
            
            return distance
        
        node1_distances = shortest_path(node1)
        node2_distances = shortest_path(node2)
        
        # print(f"node1_distances: {node1_distances} \n")
        # print(f"node2_distances: {node2_distances} \n")
        
        ans , max_distance = inf , inf 
        
        for node in range(n):
            curr_max_distance = max(node1_distances[node] , node2_distances[node])
            
            # if we can minimize the distance then take min_distance where both node can reach
            
            if curr_max_distance != inf:
                # if they are euqal take the min node
                if curr_max_distance == max_distance:
                    ans = min(ans , node)
                elif curr_max_distance < max_distance:
                    max_distance = curr_max_distance
                    ans = node  
        
        return -1 if ans == inf else ans
            

sol = Solution()

print(sol.closestMeetingNode(edges = [2,2,3,-1], node1 = 0, node2 = 1))
print(sol.closestMeetingNode(edges = [1,2,-1], node1 = 0, node2 = 2))        