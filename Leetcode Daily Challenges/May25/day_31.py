from typing import List 
from collections import deque

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        
        # make the board 1D first
        def flatten(board):
            arr = []
            """ 
            start from last row , first column
            Go left to right
            if current position is the last column then go to the first column of the upper row
            """
            left_to_right = True # start from left to right
            
            for r in reversed(range(n)):
                row = board[r] # take the full row
                
                if left_to_right: # if left to right then add then row as it is
                    arr.extend(row)
                else: # if right_to_left then reverse it and then add
                    arr.extend(reversed(row))
                left_to_right = not left_to_right
            
            return arr
        
        flat_board = flatten(board)
        
        # use BFS to find the minimum moves
        visited = [False] * (n * n)
        
        queue = deque([(0 , 0)]) # (index , steps)
        
        while queue:
            index , steps = queue.popleft()
            
            # if we reached the last index
            if index == n*n - 1:
               return steps
            
            # otherwise move from 1 to 6
            for move in range(1 , 7):
                next_index = index + move 
                # if not a valid index
                if next_index >= n * n:
                    continue 
                
                # otherwise take the move and go the position
                dest = flat_board[next_index]
                
                # check dest position has a snake or not
                if dest != -1: # has a snake or ladder
                   next_index = dest - 1
                
                if not visited[next_index]:
                    visited[next_index] = True
                    queue.append((next_index , steps + 1))
        
        return -1
                    