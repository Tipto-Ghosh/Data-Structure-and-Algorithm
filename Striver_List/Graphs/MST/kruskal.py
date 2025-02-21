# For Kruskal we need 3 functions
# 1. make set
# 2. find parent
# 3. make union

# In kruskal function
# step-1: make the set
# From the spannig make a min_heap[or sort the edge list] to find the smallest weight edge every time
# step-2: take the edge with lowest weight and call union_set

# Union_set:
# find parent of u and v
# add small rank member with the bigger one. If both size is same add with any one and increase the rank/size


from typing import List
class Solution:
    def spanningTree(self, V: int, adj: List[List[int]]) -> int:
        
        # make set method
        parent = [i for i in range(V)]
        rank = [0] * V
        
        def find_parent(node: int) -> int:
            if parent[node] == node:
                return parent[node]
            
            p = find_parent(parent[node])
            parent[node] = p # path compression
            return p
        
        def union_set(u: int , v: int) -> None:
            # find the parent of u and v
            parent_u = find_parent(u)
            parent_v = find_parent(v)
            
            # already in the same set
            if parent_u == parent_v:
                return
            
            
            if rank[parent_u] > rank[parent_v]: # u has a bigger tree so add v to u
               parent[parent_v] = parent_u
            elif rank[parent_v] > rank[parent_u]: # v has a bigger tree so add u to v
               parent[parent_u] = parent_v 
            else: # both has same size tree. Then add with anyone
                parent[parent_v] = parent_u
                rank[parent_u] += 1
                
        
        # convert the adj_list to edge_list
        edges = []
        for u in range(V):
            for v , w in adj[u]:
                if u < v:
                    edges.append((w , u , v))
                    
        # sort all the edge's based on weight
        edges.sort()
        
        count_edge = 0 # Total edge will be (V - 1)
        total_cost = 0
        
        for weight , u , v in edges:
            if find_parent(u) != find_parent(v):
                union_set(u , v)
                total_cost += weight
                count_edge += 1
                
                if count_edge == V - 1:
                    break
        
        return total_cost