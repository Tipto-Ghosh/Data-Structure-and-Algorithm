from typing import List 
from collections import defaultdict
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # Step-1: Make the adjacency List
        # Step-2: Apply DFS and store all the components vertices
        # Step-3: Go to every Component and check is_complete component
        # If in-degree of every vertex is total_vertex_in_this_component - 1
        
        adjList = defaultdict(list)
        indegree = [0] * n 
        
        for u , v in edges:
            adjList[u].append(v)
            adjList[v].append(u)
            indegree[v] += 1
            indegree[u] += 1
        
        visited = [False] * n 
        
        def DFS(node: int , curr_component: List[int]):
            # Take the curr node
            curr_component.append(node)
            visited[node] = True
            
            # Go for all neiNode
            for neiNode in adjList[node]:
                if not visited[neiNode]:
                    DFS(neiNode , curr_component)
                     
        
        def is_complete(component: List[int]) -> bool:
            total_vertices = len(component)
            for node in component:
                if indegree[node] != total_vertices - 1:
                    return False
            
            return True 
        
        all_components = []
        for node in range(n):
            if not visited[node]:
               curr_component = []
               DFS(node , curr_component)
               all_components.append(curr_component)
        
        # print(f"All Comp: {all_components}")
        count = 0
        for curr_comp in all_components:
            if is_complete(curr_comp):
                count += 1  
        
        return count        



sol = Solution()

print(sol.countCompleteComponents(6 , [[0,1],[0,2],[1,2],[3,4]]))

print(sol.countCompleteComponents(6 , [[0,1],[0,2],[1,2],[3,4],[3,5]]))
