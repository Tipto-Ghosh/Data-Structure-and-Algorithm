class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        """
        loop i from 1 to n+1
        if i % m == 0 --> take in num1
        else take in num2
        return num1 - num2
        
        basically we have to find out the difference of not divisible and divisible
        """
        ans = 0
        
        for num in range(1 , n + 1):
            # if not divisible then add the num
            if num % m != 0:
                ans += num 
            else: # substract num
                ans -= num
        
        return ans 
        

sol = Solution()

print(sol.differenceOfSums(10 , 3))
print(sol.differenceOfSums(5 , 6))
print(sol.differenceOfSums(5 , 1))