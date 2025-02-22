from typing import List
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS , COLS = len(board) , len(board[0])
        directions = [(1,0) , (-1,0) , (0,1) , (0,-1)]
        # start with (r,c) where board[r,c] == s[0]
        # at any time I have 4 choice to go
        def backtrack(row:int , col:int , word_index:int , vis:set) -> bool:
            if word_index == len(word):
                return True
            if row < 0 or col < 0 or row >= ROWS or col >= COLS or (row , col) in vis or board[row][col] != word[word_index]:
                return False
            # if we are in a right path then take the curr_letter
            vis.add((row , col)) 
            # we have 4 options to choose
            for dr , dc in directions:
                nr , nc = row + dr , col + dc
                # if valid row and col
                if backtrack(nr , nc , word_index + 1 , vis):
                    return True
            # undo part
            vis.remove((row , col))
            return False
            
        for r in range(ROWS):
           for c in range(COLS): 
               if board[r][c] == word[0]:
                   vis = set()
                   if backtrack(r , c , 0 , vis):
                       return True
        return False

sol = Solution()
# board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
# word = "ABCCED"
board = [['a']]
word = 'a'
print(sol.exist(board , word))