class Solution:
    def all_longest_common_subsequences(self , s , t):
        # len_s , len_t = len(s) , len(t)
        # dp = [[-1] * (len_t + 1) for _ in range(len_s + 2)]
        # def solve(index_s: int , index_t: int) -> int:
        #     if index_s < 0 or index_t < 0:
        #         return 0
        #     if dp[index_s][index_t] != -1:
        #         return dp[index_s][index_t]
        #     matched , dont_matched = 0 , 0
        #     if s[index_s] == t[index_t]:
        #         matched = 1 + solve(index_s - 1 , index_t - 1)
        #     else:
        #         dont_matched = max(solve(index_s - 1 , index_t) , solve(index_s , index_t - 1))
        #     dp[index_s][index_t] = max(matched , dont_matched)
        #     return dp[index_s][index_t]    
        # return solve(len_s - 1 , len_t - 1)    
        
        len_s , len_t = len(s) , len(t)
        dp = [[0] * (len_t + 1) for _ in range(len_s + 2)]
        
        for index_s in range(1 , len_s + 1):
            for index_t in range(1 , len_t + 1):
                if s[index_s - 1] == t[index_t - 1]:
                    dp[index_s][index_t] = 1 + dp[index_s - 1][index_t - 1]
                else:
                    dp[index_s][index_t] = max(dp[index_s - 1][index_t] , dp[index_s][index_t - 1])
        
        lcs = []
        index_s , index_t = len_s , len_t
        while index_s > 0 and index_t > 0:
            if s[index_s - 1] == t[index_t - 1]:
                lcs.append(s[index_s - 1])
                index_s -= 1
                index_t -= 1 
            elif dp[index_s][index_t - 1] >= dp[index_s - 1][index_t]:
                index_t -= 1
            else:
                index_s -= 1
        
        lcs.reverse()        
        return ''.join(lcs)


sol = Solution()
s = 'abaaa'
t = 'baabaca'

print(sol.all_longest_common_subsequences(s , t))            