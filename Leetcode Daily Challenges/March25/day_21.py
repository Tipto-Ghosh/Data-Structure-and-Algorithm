# Created By: Tipto Ghosh
# Creation Time: 2025/03/21 08:00:47

from collections import defaultdict , deque
from typing import List
class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        # Here we have dependencies with recipes to supplies and also recipes to recipes
        # Before making one recipe we have to make sure that all ingredients has been present
        # Topological Sort[Kahn's Algo]
        # Here all the elements that are present in supplies has no dependencies, so their indegree is zero
        # We will track the indegree with a Hashmap
        
        indegree = defaultdict(int)
        queue = deque()
        
        for ele in supplies:
            indegree[ele] = 0 # No dependency
            queue.append(ele)
        
        # Now we need the adjList
        adjList = defaultdict(list)
        
        for i in range(len(recipes)):
            # for recipe i we need ingredients at i. So their is an edge from ingredient i to recipe i
            for ingredient in ingredients[i]:
                indegree[recipes[i]] += 1
                adjList[ingredient].append(recipes[i])
                
        recipes_set = set(recipes)
        we_can_make = []
        # Now we can simply apply Kahn's algorithm
        while queue:
            curr_supply = queue.popleft()
            # If current supply is in recipes then we can make it. To check we need a quick checker so convert the recipes in a set
            if curr_supply in recipes_set:
                we_can_make.append(curr_supply)
            
            # Now check all the other recipies that is dependent on curr_supply
            for other_recipe in adjList[curr_supply]:
                # we have curr_supply so we can remove this curr_supply's dependency
                indegree[other_recipe] -= 1
                if indegree[other_recipe] == 0: # If other_recipe has no more dependency we can make it
                    queue.append(other_recipe)
        
        return we_can_make         
        
        
        
sol = Solution()

print(sol.findAllRecipes(["bread"] , [["yeast","flour"]] , ["yeast","flour","corn"]))     

print(sol.findAllRecipes(["bread","sandwich"] , [["yeast","flour"],["bread","meat"]] , ["yeast","flour","meat"]))

print(sol.findAllRecipes(["bread","sandwich","burger"] , [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]] , ["yeast","flour","meat"]))   