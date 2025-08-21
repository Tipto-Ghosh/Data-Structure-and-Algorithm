from typing import List

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        
        rows , cols = len(matrix) , len(matrix[0])
        
        dp = [[-1] * cols for _ in range(rows)]
        
        def solve(curr_row , curr_col) -> int:
            # base case:
            if curr_row < 0 or curr_row >= rows or curr_col < 0 or curr_col >= cols:
                return 0
            
            # if current position value is 0 then also we dont have any squares of 1
            if matrix[curr_row][curr_col] == 0:
                return 0
            
            if dp[curr_row][curr_col] != -1:
                return dp[curr_row][curr_col]
            
            # Find the largest square of ones for current position
            
            # go right
            right = solve(curr_row , curr_col + 1)
            
            # go down
            down = solve(curr_row + 1 , curr_col)
                
            # go diagonal
            diagonal = solve(curr_row + 1 , curr_col + 1)
            
            # take min length of all
            dp[curr_row][curr_col] = 1 + min([right , down , diagonal])
            return dp[curr_row][curr_col] 
        
        
        count = 0
        
        for row in range(rows):
            for col in range(cols):
                if matrix[row][col] == 1:
                    count += solve(row , col)
        
        return count 


sol = Solution()

print(sol.countSquares(matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]))
print(sol.countSquares(matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]))        