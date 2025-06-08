from typing import List
 
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        
        def DFS(curr_num: int) -> None:
            # If we are out of bounds
            if curr_num > n:
                return
            
            # We are in range so take the curr_num
            ans.append(curr_num)
            
            # Now make next nums by adding 1 digit at the end of curr_num
            for digit in range(10): # 0 to 9
                next_num = (curr_num * 10) + digit
                
                # If next_num in range
                if next_num <= n:
                    DFS(next_num)
                else:
                    break # or return 
        
        
        # take digits from 1 to 9
        for num in range(1 , 10):
            DFS(num)
        
        return ans  
        
sol = Solution()

print(sol.lexicalOrder(23)) 