class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        
        for p in range(0 , 32):
            val = 3 ** p 
            
            if val == n:
                return True 
        
        return False    
        
        
sol = Solution()

print(sol.isPowerOfThree(27))
print(sol.isPowerOfThree(0))
print(sol.isPowerOfThree(1))
print(sol.isPowerOfThree(-1))        