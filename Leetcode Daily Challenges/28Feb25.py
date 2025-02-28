class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        # So Take the common part once and take the uncommon part from both
        # Find the common part[LCS]
        # Now print the LCS and when we are switching ups or left then take the uncommon part
        n1 , n2 = len(str1) , len(str2)
        # Step-01: Find the LCS
        dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]
        
        for i in range(1 , n1 + 1):
            for j in range(1 , n2 + 1):
                # If common letter
                if str1[i-1] == str2[j - 1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1])
        
        # Now as print the LCS do the same. 
        # But when we are moving from the uncommon letter take the uncommon part also
        ans = []
        i , j = n1 , n2
        
        while i > 0 and j > 0:
            # If common letter
            if str1[i-1] == str2[j-1]:
                ans.append(str1[i-1])
                i -= 1
                j -= 1
            # If not common move up/left[max number]
            elif dp[i-1][j] > dp[i][j-1]: # move up
                ans.append(str1[i - 1]) 
                i -= 1
            else: # Move down
                ans.append(str2[j - 1])
                j -= 1
        
        # if i <= 0 then there is some letter left at str2
        while j > 0:
            ans.append(str2[j-1])
            j -= 1
        # if j <= 0 then there is some letter left at str1
        while i > 0:
            ans.append(str1[i - 1])
            i -= 1
            
        return ''.join(reversed(ans)) 
                
                
sol = Solution()

str1 , str2 = "abac" , "cab"
print(sol.shortestCommonSupersequence(str1 , str2))

str1 , str2 = "aaaaaaaa" , "aaaaaaaa"
print(sol.shortestCommonSupersequence(str1 , str2))                