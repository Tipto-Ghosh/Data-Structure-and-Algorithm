class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # https://leetcode.com/problems/fraction-to-recurring-decimal/?envType=daily-question&envId=2025-09-24
        
        if numerator == 0:
            return "0"
        
        ans = []
        
        # handle the -ve sign if any
        if (numerator < 0) ^ (denominator < 0): # single -ve True , both -ve False.
            ans.append("-")
        
        numerator , denominator = abs(numerator) , abs(denominator)
        
        # int part division
        val = numerator // denominator
        remainder = numerator % denominator
        # store the int part as it is
        ans.append(str(val))
        
        # if no remainder then return the ans as it is.
        if remainder == 0:
            return "".join(ans)
        
        # add the "."
        ans.append(".")
        # now check repeating terms in fraction part
        remainder_map = {} # remainder -> index in ans
        while remainder:
            # if remainder is a repeating term then add ( at first
            if remainder in remainder_map:
                index = remainder_map[remainder] # position of the curr remainder
                ans.insert(index , "(")
                # at the end add )
                ans.append(")")
                break
            
            # otherwise
            remainder_map[remainder] = len(ans)
            remainder *= 10
            ans.append(str(remainder // denominator))
            remainder %= denominator
        
        return "".join(ans)
        
        
                
sol = Solution()
print(sol.fractionToDecimal(4 , 333))