from typing import List
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        # We can use even digits at even index
        # and at odd digit we can only use 2 , 3 , 5 , 7
        even_digits = [0,2,4,6,8]
        prime_digits = [2,3,5,7]
        
        mod = (10 ** 9) + 7
        
        def helper(index: int) -> int:
            # base case: if we had a n-length number means a valid number
            if index == n:
                if (index - 1) % 2 == 0:
                    return len(even_digits)
                else:
                    return len(prime_digits)
            
            count = 0
            
            # If even index
            if index % 2 == 0:
                count = (len(even_digits) * helper(index + 1)) % mod
            else:
                count = (len(prime_digits) * helper(index + 1)) % mod
            
            return count        
        
        
        return helper(0)
        
sol = Solution()

print(sol.countGoodNumbers(1))
print(sol.countGoodNumbers(4))
print(sol.countGoodNumbers(50))        