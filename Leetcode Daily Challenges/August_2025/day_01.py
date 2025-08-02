from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        """ 
        if we start level from 0 then
        size at level n = n + 1
        first and last element will be always 1
        
        if we are at row r and col c then val[r][c] = val[r - 1][c - 1] + val[r - 1][c]
        """
        
        ans = []
        prev_level = []
        
        for row in range(numRows):
            curr_level_size = row + 1
            curr_vals = [1] * curr_level_size
            
            for col in range(1 , curr_level_size - 1):
                curr_vals[col] = prev_level[col - 1] + prev_level[col]
            
            prev_level = curr_vals
            ans.append(curr_vals)
        
        return ans 


sol = Solution()

print(sol.generate(1))    
print(sol.generate(2))    
print(sol.generate(3))    
print(sol.generate(4))    