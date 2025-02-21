from typing import List
class Solution:
    # Backtracking cause we want to get all the permuations
        
        # steps:
        # 1. Base Case: if permutation length is equal to the input length then we got a valid ans,store it
        # 2. Every time fix an element
        # 3. Choose other elements[so we need to use a loop]
        # 4. Once we done with the curr choosen element then remove it from curr_ans.
    def permute(self, arr: List[int]) -> List[List[int]]:
        n = len(arr)
        ans = []
        
        def backtrack(curr , used):
            if len(curr) == n:
                ans.append(curr[:]) # we have to create a copy of curr and then we have to add it. 
                return    
            
            # explore other possibilities
            for i in range(n):
                if used[i]:
                    continue
                # Now index i is our fixed element. And explore other possibilities
                curr.append(arr[i])
                used[i] = True
                backtrack(curr , used)
                # now undo the part
                curr.pop()
                used[i] = False
            
        
        used = [False] * n
        curr = []
        backtrack(curr , used)
        return ans

sol = Solution()
arr = [1,1,2]
print(sol.permute(arr))    