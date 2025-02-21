from collections import deque
class Solution:
    def topologicalSort(self,adj):
        # count all indegree
        # find all the 0 indegree and store in queue
        # take the front from queue and go to every neighbour and reduce indegree by one
        # again take all the 0 indegree and repeat the same
        n = len(adj) # vertices are 0 to n-1
        indegree_count = [0] * n
        
        # for [u , v] in adj:
        #     indegree_count[v] += 1
        
        for neighbors  in adj:
            for neighbor in neighbors :
                indegree_count[neighbor] += 1
        
        queue = deque([node for node in range(n) if indegree_count[node] == 0])
        ans = []
        
        while queue:
            node = queue.popleft()
            ans.append(node)
            
            for neiNode in adj[node]:
                indegree_count[neiNode] -= 1
                if indegree_count[neiNode] == 0:
                    queue.append(neiNode)
        
        return ans

sol = Solution()
adj = [[], [3], [3], [], [0,1], [0,2]]

print(sol.topologicalSort(adj))