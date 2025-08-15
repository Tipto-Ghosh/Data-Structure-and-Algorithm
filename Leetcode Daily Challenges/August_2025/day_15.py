class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False 
        
        for p in range(0 , 32):
            val = 4 ** p 
            if val == n:
                return True
        
        return False 

sol = Solution()

print(sol.isPowerOfFour(16))
print(sol.isPowerOfFour(6))