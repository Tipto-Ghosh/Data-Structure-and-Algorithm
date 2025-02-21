class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # n1 , n2 = len(text1) , len(text2)
        # dp = [[-1] * (n2)] * n1 
        # def solve(index1: int , index2: int) -> int:
        #     # Base Case:
        #     # what if index out of bounds
        #     if index1 < 0 or index2 < 0:
        #         return 0
        #     # Just think both have 1 letter
        #     if index1 == 0 and index2 == 0:
        #         return 1 if text1[index1] == text2[index2] else 0 
        #     if dp[index1][index2] != -1:
        #         return dp[index1][index2]
        #     # Operation's
        #     # there can be 2 Case: curr_letter Matched , curr letter desn't matched
        #     matched , dont_matched = 0 , 0
        #     if text1[index1] == text2[index2]:
        #         matched = 1 + solve(index1 - 1 , index2 - 1)
        #     # if curr letter don't match we have 2 sub-case
        #     else:
        #         sub_case1 = solve(index1 - 1 , index2)
        #         sub_case2 = solve(index1 , index2 - 1)
        #         dont_matched = max(sub_case1 , sub_case2)
        #     # Answer
        #     dp[index1][index2] = max(matched , dont_matched)
        #     return dp[index1][index2]
        # return solve(len(text1) - 1 , len(text2) - 1)    

        n1 , n2 = len(text1) , len(text2)
        dp = [[0] * (n2 + 1)] * (n1 + 1)
        
        for index1 in range(1 , n1 + 1):
            for index2 in range(1 , n2 + 1):
                if text1[index1 - 1] == text2[index2 - 1]:
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1]
                else:
                    dp[index1][index2] = max(dp[index1][index2 - 1] , dp[index1 - 1][index2])
        return dp[n1][n2]            
sol = Solution()
text1 = "abcde"
text2 = "ace"
 
print(sol.longestCommonSubsequence(text1 , text2))