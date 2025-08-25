from typing import List

class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        rows , cols = len(matrix) , len(matrix[0])
        
        if rows == 0 or cols == 0:
            return []
        
        ans = []
        
        curr_row , curr_col = 0 , 0
        
        for _ in range(rows * cols):
            # add current element
            ans.append(matrix[curr_row][curr_col])
            
            # check move direction
            is_even_sum = (curr_row + curr_col) % 2 == 0
            
            if is_even_sum:
                if curr_col == cols - 1:
                    curr_row += 1
                elif curr_row == 0:
                    curr_col += 1
                else:
                    curr_row -= 1
                    curr_col += 1
            else:
                if curr_row == rows - 1:
                    curr_col += 1
                elif curr_col == 0:
                    curr_row += 1
                else:
                    curr_row += 1
                    curr_col -= 1
        
        return ans 

sol = Solution()
print(sol.findDiagonalOrder([[1,2,3],[4,5,6],[7,8,9]]))