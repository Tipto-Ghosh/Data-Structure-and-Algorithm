class Solution:
    def countAndSay(self, n: int) -> str:
        """
        countAndSay(1) --> 1
        countAndSay(2) --> one 1 --> 11
        countAndSay(3) --> two 1 --> 21
        countAndSay(4) --> one 2 and one 1 --> 1211
        countAndSay(5) --> one 1 , one 2 , two 1 --> 111221
        countAndSay(6) --> three 1, two 2 and one 1 --> 312211
        """
        
        def solve(val: int) -> str:
            # Base case: 
            if val == 1:
                return '1'
            
            # otherwise find what is val - 1
            prev = solve(val - 1)
            # Then count digit freqeuncy in serially
            curr = [] 
            prev_digit = prev[0]
            count = 1
            for i in range(1 , len(prev)):
                curr_digit = prev[i]
                # if we are at a different digit---> ex: 1123 we are at 2....so now set value for 1--> 21
                if curr_digit != prev_digit:
                    curr.append(str(count))
                    curr.append(prev_digit) 
                    count = 1
                    prev_digit = curr_digit 
                else:
                    count += 1 
    
            # For the last digit
            curr.append(str(count))
            curr.append(prev_digit)
            curr = ''.join(curr)
            
            return curr
        
        return solve(n)

if __name__ == '__main__':
    sol = Solution()
    print(sol.countAndSay(4))