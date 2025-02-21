from typing import List
from collections import deque , defaultdict
class Solution:
    def numProvinces(self, adj, V):
        # Given the adj-matrix make the adj_list
        adj_list = defaultdict(list)
        for u in range(len(adj)):
            for v in range(len(adj[u])):
                if adj[u][v] == 1:
                    adj_list[u + 1].append(v + 1)
        
        vis = [False] * (V + 1) # We are maintaining 1 based indexing
        #print(adj_list)             
        def BFS(node: int) -> None:
            q = deque([node])
        
            while q:
                curr_node = q.popleft()
                vis[curr_node] = True
                
                for neiNode in adj_list[curr_node]:
                    if not vis[neiNode]:
                        BFS(neiNode)        
        
        num_prov = 0
        for node in adj_list.keys():
            if not vis[node]:
                BFS(node)
                num_prov += 1
                
        return num_prov



sol = Solution()
adj = [
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

ans = sol.numProvinces(adj , 3)
print(ans)