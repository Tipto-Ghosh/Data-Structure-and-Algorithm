class Solution:
    def soupServings(self, n: int) -> float:
        """ 
        If A is already less than equal zero then probability of being A empty is 1.
        if A and B both are less than equal zero then half of the probability will be -
        P(A_empty U B_empty) = P(A_empty) + P(B_empty) and half will be 0.5 * P(A_empty U B_empty)
        P(A_empty U B_empty) = 1 * 0.5 = 0.5
        
        """
        if(n > 4800):
            return 1.0
        
        all_operations = [(100 , 0) , (75 , 25) , (50 , 50) , (25 , 75)]
        
        dp = [[-1.0] * (n + 1) for _ in range(n + 2)]
        
        def solve(A , B) -> float: 
            if A <= 0 and B <= 0:
                return 0.5
            if A <= 0:
                return 1
            if B <= 0:
                return 0.0
            
            if dp[A][B] != -1.0:
                return dp[A][B]    
            
            prob = 0
            
            for take_A , take_B in all_operations:
                A_remain = A - take_A
                B_remain = B - take_B
                
                prob += solve(A_remain , B_remain)
            
            dp[A][B] = 0.25 * prob
            return dp[A][B]
        
        return solve(n , n)    
            
sol = Solution()
print(sol.soupServings(50))
print(sol.soupServings(100))            