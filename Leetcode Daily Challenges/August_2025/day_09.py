class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        low , high = 0 , 31
        
        while low <= high:
            mid = (low + high) // 2
            val = 2 ** mid 
            
            if val == n:
                return True
            elif val > n:
                high = mid - 1
            else:
                low = mid + 1
        
        return False
    

sol = Solution()

print(sol.isPowerOfTwo(1))
print(sol.isPowerOfTwo(16))
print(sol.isPowerOfTwo(3))