from collections import defaultdict
import heapq
# n --> Num of vertices, m = num of edges , g = edge's list[u , v , weight]
def calculatePrimsMST(n, m, g):
    adj = [[] for _ in range(n)]
    for u , v , w in g:
        adj[u - 1].append((w , v - 1)) # making 0-based indexing
        adj[v - 1].append((w , u - 1))
        
    parent = [-1] * n
    key = [float('inf')] * n
    inMst = [False] * n
    
    # start with a node
    start_node = 0
    min_heap =  [(0 , start_node)]
    key[start_node] = 0
    
    while min_heap:
        weight , u = heapq.heappop(min_heap)
        
        if inMst[u]:
            continue
        
        inMst[u] = True
        
        for w , v in adj[u]:
            if not inMst[v] and w < key[v]:
                key[v] = w
                parent[v] = u
                heapq.heappush(min_heap , (w , v))
    
    tree_edges = [] # [u , v , weight]
    for node in range(1 , n): # skip the first node cause it has no parent
        if parent[node] != -1: # if parent[node] == -1 means this node is not a part of MST.
           tree_edges.append([parent[node] + 1 , node + 1 , key[node]])
    
    return tree_edges
    