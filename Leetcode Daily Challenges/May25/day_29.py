class Solution:
    
    def buildList(self, edges):
        # Number of nodes is edges + 1 (since it's a tree)
        n = len(edges) + 1
        
        # Initialize adjacency list
        adj = [[] for _ in range(n)]
        
        # Build undirected graph
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        return adj

    def dfsColor(self, adj, u, parent, color, isA):
        """
        DFS to color nodes with alternating 0 and 1 representing even and odd distances.
        Also count how many even/odd nodes are there in this tree (Tree A or B).
        """
        if color[u] == 0:
            if isA: self.evenA += 1  # Even node in Tree A
            else: self.evenB += 1    # Even node in Tree B
        else:
            if isA: self.oddA += 1   # Odd node in Tree A
            else: self.oddB += 1     # Odd node in Tree B
        
        for v in adj[u]:
            if v != parent:
                color[v] = color[u] ^ 1  # Alternate color: 0→1 or 1→0
                self.dfsColor(adj, v, u, color, isA)

    def maxTargetNodes(self, edges1, edges2):
        # Build adjacency lists for both trees
        adjA = self.buildList(edges1)
        adjB = self.buildList(edges2)
        
        n, m = len(adjA), len(adjB)  # Number of nodes in each tree

        # Initialize color arrays (0 = even, 1 = odd)
        colorA = [-1] * n
        colorB = [-1] * m

        # Initialize counts for Tree A and Tree B
        self.evenA = self.oddA = self.evenB = self.oddB = 0

        # Start coloring from root node (0) for both trees
        colorA[0] = 0
        self.dfsColor(adjA, 0, -1, colorA, isA=True)

        colorB[0] = 0
        self.dfsColor(adjB, 0, -1, colorB, isA=False)

        # Choose the maximum of even or odd nodes in Tree B
        # Because we only add one edge from A → B, the parity flips
        maxiB = max(self.evenB, self.oddB)

        # Compute final result
        res = [0] * n
        for i in range(n):
            if colorA[i] == 0:
                # If node i in A is at even depth, pair with maximum in B (odd or even doesn't matter for max)
                res[i] = self.evenA + maxiB
            else:
                # If node i in A is at odd depth, count oddA nodes + maximum in B
                res[i] = self.oddA + maxiB

        return res



sol = Solution()
print(sol.maxTargetNodes(
    edges1=[[0,1],[0,2],[2,3],[2,4]],
    edges2=[[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
))
