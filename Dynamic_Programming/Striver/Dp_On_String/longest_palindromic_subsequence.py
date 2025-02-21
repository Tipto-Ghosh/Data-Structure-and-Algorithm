class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # t = s[ : : -1]
        # n = len(s)
        
        # dp = [[-1] * (n) for _ in range(n)]
                
        # def solve(index_s: int , index_t: int) -> int:
        #     if index_s < 0 or index_t < 0:
        #         return 0
        #     if dp[index_s][index_t] != -1:
        #        return dp[index_s][index_t] 
            
        #     matched , dont_macthed = 0 , 0
        #     if s[index_s] == t[index_t]:
        #         matched = 1 + solve(index_s - 1 , index_t - 1)
        #     else:
        #         dont_macthed = max(solve(index_s - 1 , index_t) , solve(index_s , index_t - 1))
            
        #     ans = max(matched , dont_macthed)
        #     dp[index_s][index_t] = ans
        #     return ans
        
        # return solve(n - 1 , n - 1)
        
        n = len(s)
        t = s[ : : -1]
        
        dp = [[0] * (n + 1)  for _ in range(n + 1)]
        
        for index_s in range(1 , n + 1):
            for index_t in range(1 , n + 1):
                if s[index_s - 1] == t[index_t - 1]: 

sol = Solution()
s = "bbbab"
print(sol.longestPalindromeSubseq(s))   

s = "cbbd"
print(sol.longestPalindromeSubseq(s))   
        