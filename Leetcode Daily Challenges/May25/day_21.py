from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        """
        So we have to know that where the 0's are present.
        Take 2 set's one for row and one for cols.
        Go through every element and if it's a 0 then store the row and col.
        After that take each row and col and make it zero 
        """
        Rows , Cols = len(matrix) , len(matrix[0])
        
        zero_rows , zero_cols = set() , set()
        
        for row in range(Rows):
            for col in range(Cols):
                if matrix[row][col] == 0:
                    zero_rows.add(row)
                    zero_cols.add(col)
        
        # Set all zero_row to 0
        for row in zero_rows:
            for c in range(Cols):
                matrix[row][c] = 0
        
        # Set all zero_cols to 0
        for col in zero_cols:
            for r in range(Rows):
                matrix[r][col] = 0
        