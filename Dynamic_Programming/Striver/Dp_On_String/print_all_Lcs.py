class Solution:
    def all_longest_common_subsequences(self, s, t):
        m, n = len(s), len(t)
        
        # Step 1: Build the DP table
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        # Step 2: Backtrack to find all LCS
        def backtrack(i, j):
            if i == 0 or j == 0:
                return {""}
            if s[i - 1] == t[j - 1]:
                return {lcs + s[i - 1] for lcs in backtrack(i - 1, j - 1)}
            else:
                lcs_set = set()
                if dp[i - 1][j] == dp[i][j]:
                    lcs_set.update(backtrack(i - 1, j))
                if dp[i][j - 1] == dp[i][j]:
                    lcs_set.update(backtrack(i, j - 1))
                return lcs_set
        
        # Start backtracking from the last cell
        lcs_set = backtrack(m, n)
        
        # Step 3: Sort LCS in lexicographical order
        return sorted(lcs_set)
