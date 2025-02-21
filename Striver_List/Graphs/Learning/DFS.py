class Solution:
    # Given a connected undirected graph represented by an adjacency list adj
    def dfsOfGraph(self, adj):
      n = len(adj)
      vis = [False] * n
      ans = []
      
      def DFS(node: int) -> None:
          ans.append(node)
          vis[node] = True
          
          for neiNode in adj[node]:
              if not vis[neiNode]:
                  DFS(neiNode)  
      
      for node in range(n):
          if not vis[node]:
              DFS(node)
      return ans   
