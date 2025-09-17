from typing import List  

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        
        def gcd(a , b):
            while b != 0:
                a , b = b , a % b 
            return a 
        
        def lcm(a , b):
            return abs(a * b) // gcd(a , b)         
        
        stack = []
        
        for num in nums:
            # check if stack top(prev of num) and num is non-coprime or not
            while stack and gcd(num , stack[-1]) > 1:
                num = lcm(stack.pop() , num)
            stack.append(num)
        
        return stack


sol = Solution()
print(sol.replaceNonCoprimes([6,4,3,2,7,6,2]))
print(sol.replaceNonCoprimes([2,2,1,1,3,3,3]))