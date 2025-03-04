class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        # we have to come number whisch is less than 3
        # Then is 2 option: 1 , 2: if 2 then it's not possible to get 2 with any power of 3
        # If it's 1 then pow(3,0) == 1 so it's possible
        ans = True
        while n > 0:
            if n % 3 == 2:
                ans = False
                break
            n //= 3
        return ans