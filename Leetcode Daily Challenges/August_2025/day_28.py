from typing import List

class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)

        # Sort a diagonal starting from (row, col)
        def sortDiagonal(row: int, col: int, reverse: bool):
            i, j = row, col
            elements = []
            
            # collect diagonal
            while i < n and j < n:
                elements.append(grid[i][j])
                i += 1
                j += 1
            
            # sort according to requirement
            elements.sort(reverse=reverse)
            
            # put back
            i, j, k = row, col, 0
            while i < n and j < n:
                grid[i][j] = elements[k]
                i += 1
                j += 1
                k += 1

        # Lower-left (including main diagonal) → descending
        for row in range(n):
            sortDiagonal(row, 0, reverse=True)

        # Upper-right (excluding main diagonal) → ascending
        for col in range(1, n):
            sortDiagonal(0, col, reverse=False)

        return grid


def print_grid(grid):
    n = len(grid)
    for r in range(n):
        for c in range(n):
            print(f"{grid[r][c]:2}", end=" ")
        print()
    print()


sol = Solution()
ans = sol.sortMatrix([[1,7,3],[9,8,2],[4,5,6]])  
print_grid(ans)          

ans2 = sol.sortMatrix([[0,1],[1,2]])
print_grid(ans2)
