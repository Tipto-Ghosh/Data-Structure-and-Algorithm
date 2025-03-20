from typing import List
import heapq
from collections import defaultdict , deque
class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        # Disjoint Set Union (DSU) to manage components
        parent = [i for i in range(n)]
        rank = [0] * n
        cost = [0xFFFFFFFF] * n  # Initialize with maximum value (all bits set)

        def find(x: int) -> int:
            if parent[x] != x:
                parent[x] = find(parent[x])  # Path compression
            return parent[x]

        def union(u: int, v: int, w: int):
            root_u = find(u)
            root_v = find(v)

            if root_u != root_v:
                # Union by rank
                if rank[root_u] > rank[root_v]:
                    parent[root_v] = root_u
                    cost[root_u] &= w
                elif rank[root_u] < rank[root_v]:
                    parent[root_u] = root_v
                    cost[root_v] &= w
                else:
                    parent[root_v] = root_u
                    rank[root_u] += 1
                    cost[root_u] &= w

        # Process all edges
        for u, v, w in edges:
            union(u, v, w)

        # Handle cost propagation to root components
        for u, v, w in edges:
            root_u = find(u)
            root_v = find(v)
            cost[root_u] &= w
            cost[root_v] = cost[root_u]  # Update cost for the root of v

        # Answer the queries
        ans = []
        for s, t in query:
            if s == t:
                ans.append(0)
            elif find(s) != find(t):
                ans.append(-1)
            else:
                ans.append(cost[find(s)])
        
        return ans
             
sol = Solution()

print(sol.minimumCost(5 , [[0,1,7],[1,3,7],[1,2,1]] , [[0,3],[3,4]]))

print(sol.minimumCost(3 , [[0,2,7],[0,1,15],[1,2,6],[1,2,1]] , [[1,2]]))             