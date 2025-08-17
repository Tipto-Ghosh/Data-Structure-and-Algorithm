class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        
        # dp = {}
        
        # # start at score , return the probability
        # def dfs(score):
        #     # base: if score is greater than equal to k we reached at base
        #     if score >= k:
        #         # now return the prob
        #         return 1 if score <= n else 0
            
        #     # do the dp part
        #     if score in dp:
        #         return dp[score]
            
        #     # calculate the prob
        #     prob = 0
            
        #     # for current score do total k branches
        #     for i in range(1 , maxPts + 1):
        #         if score + i > n:
        #            break
        #         prob += dfs(score + i)    
            
        #     # count the prob
        #     dp[score] = prob / maxPts
        #     return dp[score]
        
        # return dfs(0)
        
        
        
        # dp = [0.0] * (n + 1) # dp[i] = prob of reaching score i
        # dp[0] = 1.0 # prob of score is 0 is 1 
        
        # # now calculate score from 1 to n
        # for curr_score in range(1 , n + 1):
        #     # now make loop[the inner for loop of dfs solution]
        #     for draw in range(1 , maxPts + 1):
        #         # previous score will be curr - draw
        #         # cause we are getting curr_score by adding draw with prev score
        #         prev_score = curr_score - draw
                
        #         # now check prev_score is valid or not
        #         # cause score starts at 0 and ends when score >= k
        #         if 0 <= prev_score < k:
        #             # now find prob of current score
        #             dp[curr_score] += (dp[prev_score] / maxPts)
        
        # # now total prob will be sum of all dp
        # # final ans will be sum of element from index k to n
        # # cause alice take points from k to n
        # return sum(dp[k : ]) 
        
        
        
        
        if k == 0 or n >= k + maxPts - 1:
            return 1.0
        
        dp = [0.0] * (n + 1)
        dp[0] = 1.0
        
        # running sum of the last maxPts dp values that are < k
        s = 1.0
        
        for score in range(1 , n + 1):
            dp[score] = s / maxPts
            
            # if score < k we take the current score also
            if score < k:
                s += dp[score]
                
            win = score - maxPts
            if  0 <= win < k:
                s -= dp[win]
        
        return sum(dp[k : ])
                
            
        

sol = Solution()

print(sol.new21Game(n = 10, k = 1, maxPts = 10))
print(sol.new21Game(n = 6, k = 1, maxPts = 10))
print(sol.new21Game(n = 21, k = 17, maxPts = 10))        