from typing import List
from collections import defaultdict , deque

class Solution:
    
    def countNumOfNodesAtDistanceK(self , n , adjList , k) -> List[int]:
        count = [0] * n 
        
        for node in range(n):
            # Find the count for every node
            
            visited = [False] * n 
            queue = deque([(node , 0)])
            visited[node] = True
            total = 1 # node itself in included
            
            while queue:
                curr_node , dist = queue.popleft()
                
                if dist == k:
                    continue
                
                for neighbor in adjList[curr_node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        total += 1
                        queue.append((neighbor , dist + 1))
            
            # done counting for node
            count[node] = total
        
        return count
    
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        '''
        Make the adjcency list for both graph(undirected-tree)
        now take every node of tree-1 and find each node find the number of nodes at a distance of at most k 
        now take every node of tree-2 and find each node find the number of nodes at a distance of at most k-1 
        
        then sum of the both tree node count at each node
        '''
        
        adjList1 = defaultdict(list)
        for u , v in edges1:
            adjList1[u].append(v)
            adjList1[v].append(u)
            
        adjList2 = defaultdict(list)
        for u , v in edges2:
            adjList2[u].append(v)
            adjList2[v].append(u)        
        
        n , m = len(edges1) + 1 , len(edges2) + 1
        
        countForTree1 = self.countNumOfNodesAtDistanceK(n , adjList1 , k)
        

        if k > 0:
           countForTree2 = self.countNumOfNodesAtDistanceK(m , adjList2 , k - 1) # k can't be -ve
           # find the max count from countTree2
           max_from_tree2 = max(countForTree2)
        else:
            max_from_tree2 = 0
        
        ans = [count + max_from_tree2 for count in countForTree1]
        return ans 

sol = Solution()

print(sol.maxTargetNodes(edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2))   
print(sol.maxTargetNodes(edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1)) 
print(sol.maxTargetNodes([[0,1]] , [[0,1]] , 0))    