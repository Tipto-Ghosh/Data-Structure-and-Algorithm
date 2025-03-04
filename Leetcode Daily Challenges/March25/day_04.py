class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        # we have to come number whisch is less than 3
        # Then is 2 option: 1 , 2: if 2 then it's not possible to get 2 with any power of 3
        # If it's 1 then pow(3,0) == 1 so it's possible
        # ans = True
        # while n > 0:
        #     if n % 3 == 2:
        #         ans = False
        #         break
        #     n //= 3
        # return ans
        
        # ------------------------- Using Bactracking -------------------------
        
        def backtrack(curr_val: int , curr_pow: int) -> bool:
            # Base Case: if curr_val is 0 we can form n
            if curr_val == 0:
                return True
            # if adding this curr_pow exceed the n then no way to form n
            if 3 ** curr_pow > n:
                return False
            
            # At each call we have 2 choice: take , skip
            
            # Option 1: Include the current power of 3 and subtract it from n
            include = backtrack(curr_val - 3 ** curr_pow , curr_pow + 1)
            if include:
                return True
            # Option 2: Skip the current power of 3 and try with the next power
            exclude = backtrack(curr_val , curr_pow + 1)
            return exclude
        
        return backtrack(n , 0)    
        
        
        
sol = Solution()        

print(sol.checkPowersOfThree(12))        
print(sol.checkPowersOfThree(91))        
print(sol.checkPowersOfThree(21))      