from typing import List
from collections import defaultdict , deque
class Solution:
    def count_components(self , n: int , edges: List[List[int]]) -> int:
        
        #make the adjList
        adjList = defaultdict(list)
        for u , v in edges:
            adjList[u].append(v)
            adjList[v].append(u)
        
        vis = [False] * n
            
        def BFS(node: int) -> None:
            q = deque([node])
            vis[node] = True
            
            while q:
                curr_node = q.popleft()
                
                for neiNode in adjList[curr_node]:
                    if not vis[neiNode]:
                        vis[neiNode] = True
                        q.append(neiNode)
              
        components = 0
        for i in range(n):
            if not vis[i]:
                components += 1
                BFS(i)
        return components