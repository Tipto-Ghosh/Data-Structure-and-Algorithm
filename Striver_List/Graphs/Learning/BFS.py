from typing import List
from collections import deque
class Solution:
    #Given a connected undirected graph represented by an adjacency list adj
    def bfsOfGraph(self, adj: List[List[int]]) -> List[int]:
        n = len(adj)
        vis = [False] * n   
        
        q = deque([0])
        vis[0] = True
        ans = []
        
        while q:
            node = q.popleft()
            ans.append(node)
                
            for neiNode in adj[node]:
                if not vis[neiNode]:
                    q.append(neiNode)
                    vis[neiNode] = True
        
        return ans