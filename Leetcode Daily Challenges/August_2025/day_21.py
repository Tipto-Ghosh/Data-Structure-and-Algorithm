from typing import List

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        
        rows , cols = len(mat) , len(mat[0])
        ans = 0
        
        # row[i][j] -> num of consecutive 1's ending at this position 
        row = [[0] * cols for _ in range(rows)]
        
        # 1. precompute row[i][j]
        for i in range(rows):
            for j in range(cols):
                if j == 0:
                    row[i][j] = mat[i][j] # col is 0 so if 1 then 1 consecutive 1 else 0
                else:
                    row[i][j] = 0 if mat[i][j] == 0 else 1 + row[i][j - 1]
                
                # count sub-matrices
                curr = row[i][j]
                
                for k in range(i , -1 , -1):
                    curr = min(curr , row[k][j])
                    
                    if curr == 0:
                        break
                    
                    ans += curr 
        
        return ans 
                    
        
sol = Solution()

print(sol.numSubmat([[1,0,1],[1,1,0],[1,1,0]]))         